using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Generics.BinaryTrees
{
    public class BinaryTree<T> : IEnumerable<T> where T : IComparable<T>
    {
        private bool _valueExist;
        public BinaryTree<T> Left { get; private set;  }
        public BinaryTree<T> Right { get; private set; }

        public T Value { get; private set; }

        public BinaryTree()
        {
            _valueExist = false;
        }

        public BinaryTree(T node)
        {
            Value = node;
            _valueExist = true;
        }
        
        public void Add(T item)
        {
            if (!_valueExist)
            {
                this.Value = item;
                _valueExist = true;
            } 
            else if (this.Value.CompareTo(item) >= 0)
            {
                if (this.Left == null)
                    this.Left = new BinaryTree<T>(item);
                else
                    this.Left.Add(item);
            }
            else
            {
                if (this.Right == null)
                    this.Right = new BinaryTree<T>(item);
                else
                    this.Right.Add(item);
            }
        }
        
        public void AddRange(params T[] items)
        {
            foreach (T item in items)
            {
                Add(item);
            }
        }

        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            if (!_valueExist)
            {
                yield break;
            }
            
            if (this.Left != null)
            {
                foreach (T item in this.Left)
                {
                    yield return item;
                }
            }

            yield return this.Value;
            
            if (this.Right != null)
            {
                foreach (T item in this.Right)
                {
                    yield return item;
                }
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return ((IEnumerable<T>)this).GetEnumerator();
        }
        
        public static implicit operator T[](BinaryTree<T> tree)
        {
            var result = new List<T>();
            foreach (var item in tree)
            {
                result.Add(item);
            }
            return result.ToArray();
        }
        
        public static bool operator ==(BinaryTree<T> left, BinaryTree<T> right)
        {
            if (object.Equals(left, null) && object.Equals(right, null))
            {
                return true;
            }

            if (object.Equals(left, null) || object.Equals(right, null))
            {
                return false;
            }

            return left.SequenceEqual(right);
        }
        
        public static bool operator !=(BinaryTree<T> left, BinaryTree<T> right)
        {
            return !(left == right);
        }
    }

    public class BinaryTree
    {
        public static BinaryTree<T> Create<T>(params T[] items) where T : IComparable<T>
        {
            var tree = new BinaryTree<T>();
            tree.AddRange(items);
            return tree;
        }
    }
}