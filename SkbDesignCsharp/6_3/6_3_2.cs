using System;
using System.Collections.Generic;
using System.Linq;

namespace Generics.Tables
{
    public class Table<T1, T2, T3> where T3: struct
    {
        private readonly IDictionary<KeyValuePair<T1, T2>, T3> _data;

        private IDictionary<KeyValuePair<T1, T2>, T3> Data
        {
            get { return _data; }
        }

        public Row Rows
        {
            get
            {
                return new Row(this);
            }
        }

        public Column Columns
        {
            get
            {
                return new Column(this);
            }
        }

        public Index Open
        {
            get
            {
                return new Index(this);
            }
        }

        public IndexExisted Existed
        {
            get
            {
                return new IndexExisted(this);
            }
        }
        
        public Table()
        {
            _data = new Dictionary<KeyValuePair<T1, T2>, T3>();
        }

        public void AddRow(T1 row)
        {
            if (_data.Any(x => EqualityComparer<T1>.Default.Equals(x.Key.Key, row)))
            {
                return;
            }

            if (_data.Any(x => EqualityComparer<T1>.Default.Equals(x.Key.Key, typeof(T1) == typeof(String) ? (T1)(object)String.Empty : default(T1))))
            {
                var pair = _data.First(x => EqualityComparer<T1>.Default.Equals(x.Key.Key, typeof(T1) == typeof(String) ? (T1)(object)String.Empty : default(T1)));
                _data.Remove(pair);
                _data.Add(new KeyValuePair<T1, T2>(row, pair.Key.Value), pair.Value);
                return;
            }
            
            _data.Add(new KeyValuePair<T1, T2>(row, typeof(T2) == typeof(String) ? (T2)(object)String.Empty : default(T2)), default(T3));
        }

        public void AddColumn(T2 column)
        {
            if (_data.Any(x => EqualityComparer<T2>.Default.Equals(x.Key.Value, column)))
            {
                return;
            }

            if (_data.Any(x => EqualityComparer<T2>.Default.Equals(x.Key.Value, typeof(T2) == typeof(String) ? (T2)(object)String.Empty : default(T2))))
            {
                var pair = _data.First(x => EqualityComparer<T2>.Default.Equals(x.Key.Value, typeof(T2) == typeof(String) ? (T2)(object)String.Empty : default(T2)));
                _data.Remove(pair);
                _data.Add(new KeyValuePair<T1, T2>(pair.Key.Key, column), pair.Value);
                return;
            }
            
            _data.Add(new KeyValuePair<T1, T2>(typeof(T1) == typeof(String) ? (T1)(object)String.Empty : default(T1), column), default(T3));
        }

        
        public sealed class Row
        {
            private readonly Table<T1, T2, T3> _table;

            internal Row()
            {
                
            }
            
            internal Row(Table<T1, T2, T3> table)
            {
                _table = table;
            }
            
            public int Count()
            {
                return _table.Data.Keys.Select(x => x.Key).Distinct().Count();
            }
        }
        
        public sealed class Column
        {
            private readonly Table<T1, T2, T3> _table;

            internal Column()
            {
                
            }
            
            internal Column(Table<T1, T2, T3> table)
            {
                _table = table;
            }
            
            public int Count()
            {
                return _table.Data.Keys.Select(x => x.Value).Distinct().Count();
            }
        }
        
        public sealed class Index
        {
            private readonly Table<T1, T2, T3> _table;

            internal Index()
            {
                
            }
            
            internal Index(Table<T1, T2, T3> table)
            {
                _table = table;
            }

            public T3 this[T1 row, T2 col]
            {
                get
                {
                    if (!_table.Data.Any() || _table.Data.Any(x => !EqualityComparer<T1>.Default.Equals(x.Key.Key, row) || !EqualityComparer<T2>.Default.Equals(x.Key.Value, col)))
                    {
                        return default(T3);
                    }
                    return _table.Data[new KeyValuePair<T1, T2>(row, col)];
                }
                set { _table.Data[new KeyValuePair<T1, T2>(row, col)] = value; }
            }
        }
        
        public sealed class IndexExisted
        {
            private readonly Table<T1, T2, T3> _table;

            internal IndexExisted()
            {
                
            }
            
            internal IndexExisted(Table<T1, T2, T3> table)
            {
                _table = table;
            }

            public T3 this[T1 row, T2 col]
            {
                get
                {
                    if (!_table.Data.Any() || _table.Data.Any(x => !EqualityComparer<T1>.Default.Equals(x.Key.Key, row) || !EqualityComparer<T2>.Default.Equals(x.Key.Value, col)))
                    {
                        throw new ArgumentException();
                    }
                    return _table.Data[new KeyValuePair<T1, T2>(row, col)];
                }
                
                set
                {
                    if (!_table.Data.Any() || _table.Data.Any(x => !EqualityComparer<T1>.Default.Equals(x.Key.Key, row) || !EqualityComparer<T2>.Default.Equals(x.Key.Value, col)))
                    {
                        throw new ArgumentException();
                    }
                    _table.Data[new KeyValuePair<T1, T2>(row, col)] = value;
                }
            }
        }
    }
    
}