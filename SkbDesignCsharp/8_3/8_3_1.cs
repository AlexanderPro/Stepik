using System;
using System.Collections.Generic;
using System.Reflection;
using System.Linq;
using System.Linq.Expressions;

namespace Reflection.Randomness
{
    [AttributeUsage(AttributeTargets.Property)]
    public class FromDistribution : Attribute
    {
        public Type Type { get; set; }

        public double[] Parameters { get; set; }

        public FromDistribution(Type type, params double[] parameters)
        {
            Type = type;
            Parameters = parameters;
        }
    }

    public class Generator<T> where T : new()
    {
        private IDictionary<string, IContinousDistribution> _properties;
        
        
        public Generator()
        {
            _properties = new Dictionary<string, IContinousDistribution>();
            foreach (var propertyInfo in typeof(T).GetProperties())
            {
                var attr = propertyInfo.GetCustomAttributes<FromDistribution>().SingleOrDefault();
                if (attr == null)
                {
                    _properties.Add(propertyInfo.Name, null);
                }
                else
                {
                    IContinousDistribution instance = null;
                    if (attr.Type == typeof(NormalDistribution))
                    {
                        if (attr.Parameters.Length != 0 && attr.Parameters.Length != 2)
                        {
                            throw new ArgumentException("NormalDistribution");
                        }

                        instance = attr.Parameters.Length == 0
                            ? (IContinousDistribution) Activator.CreateInstance(attr.Type)
                            : (IContinousDistribution) Activator.CreateInstance(attr.Type,
                                new object[] {attr.Parameters[0], attr.Parameters[1]});
                    }
                    else if (attr.Type == typeof(ExponentialDistribution))
                    {
                        if (attr.Parameters.Length != 1)
                        {
                            throw new ArgumentException("ExponentialDistribution");
                        }

                        instance = (IContinousDistribution) Activator.CreateInstance(attr.Type,
                            new object[] {attr.Parameters[0]});
                    }
                    else
                    {
                        throw new ArgumentException();
                    }

                    _properties.Add(propertyInfo.Name, instance);
                }
            }
        }

        public Generator(IDictionary<string, IContinousDistribution> properties)
        {
            _properties = properties;
        }

        public T Generate(Random rnd)
        {
            var obj = new T();
            foreach (var propertyInfo in obj.GetType().GetProperties())
            {
                if (_properties.ContainsKey(propertyInfo.Name))
                {
                    var property = _properties[propertyInfo.Name];
                    if (property != null)
                    {
                        propertyInfo.SetValue(obj, property.Generate(rnd));
                    }
                }
            }
            return obj;
        }

        public InnerGenerator<T> For<TResult>(Expression<Func<T, TResult>> expression)
        {
            var memberExpression = expression.Body as MemberExpression;
            if (memberExpression == null || !_properties.ContainsKey(memberExpression.Member.Name))
            {
                throw new ArgumentException();
            }
            
            var inner = new Generator<T>.InnerGenerator<T>(_properties);
            inner._selectedName = memberExpression.Member.Name;
            return inner;
        }


        public class InnerGenerator<TT> where TT : new()
        {
            private IDictionary<string, IContinousDistribution> _properties;
            internal string _selectedName;
            
            public InnerGenerator(IDictionary<string, IContinousDistribution> properties)
            {
                _properties = properties;
            }

            public Generator<T> Set(IContinousDistribution distribution)
            {
                if (_properties.ContainsKey(_selectedName))
                {
                    _properties[_selectedName] = distribution;
                }

                return new Generator<T>(_properties); 
            }
        }
    }
}