using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance.DataStructure
{
    public class Category : IComparable
    {
        public string Name { get; set; }

        public MessageType MessageType { get; set; }

        public MessageTopic Topic { get; set; }

        public Category(string name, MessageType messageType, MessageTopic topic)
        {
            Name = name;
            MessageType = messageType;
            Topic = topic;
        }
        
        public override bool Equals(object other)
        {
            if (object.Equals(other, null))
                return false;

            if (object.ReferenceEquals(this, other))
                return true;

            if (this.GetType() != other.GetType())
                return false;

            return Equals(other as Category);
        }
        
        public bool Equals(Category other)
        {
            if (object.Equals(other, null))
                return false;

            if (object.ReferenceEquals(this, other))
                return true;

            if (this.GetType() != other.GetType())
                return false;

            return (string.Compare(Name, other.Name) == 0 && MessageType == other.MessageType && Topic == other.Topic);
        }
        
        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;
                hash = hash * 23 + (Name ?? "").GetHashCode();
                hash = hash * 23 + MessageType.GetHashCode();
                hash = hash * 23 + Topic.GetHashCode();
                return hash;
            }
        }
        
        public int CompareTo(object other)
        {
            if (object.Equals(other, null)) return 1;
        
            Category category = other as Category;
            if (category != null)
            {
                if (string.Compare(Name, category.Name) == 0 && MessageType == category.MessageType && Topic == category.Topic)
                {
                    return 0;
                } else if (string.Compare(Name, category.Name) > 0)
                {
                    return 1;
                } else if (string.Compare(Name, category.Name) == 0 && MessageType > category.MessageType)
                {
                    return 1;
                } else if (string.Compare(Name, category.Name) == 0 && MessageType == category.MessageType && Topic > category.Topic)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else
                throw new ArgumentException("other");
        }

        public override string ToString()
        {
            return string.Format("{0}.{1}.{2}", Name ?? "", MessageType, Topic);
        }

        public static bool operator ==(Category left, Category right)
        {
            return !object.Equals(left, null) && !object.Equals(right, null) && left.CompareTo((object)right) == 0;
        }
        
        public static bool operator !=(Category left, Category right)
        {
            return !(left == right);
        }
        
        public static bool operator <(Category left, Category right)
        {
            return left.CompareTo((object) right) < 0;
        }

        public static bool operator <=(Category left, Category right)
        {
            return left.CompareTo((object) right) <= 0;
        }

        public static bool operator >(Category left, Category right)
        {
            return left.CompareTo((object) right) > 0;
        }

        public static bool operator >=(Category left, Category right)
        {
            return left.CompareTo((object) right) >= 0;
        }
    }
}