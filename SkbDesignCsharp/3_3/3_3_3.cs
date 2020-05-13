using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Incapsulation.Weights
{
    public class Indexer
    {
        private readonly double[] _range;
        private readonly int _start;

        public int Length { get; set; }

        public Indexer(double[] range, int start, int length)
        {
            if (start < 0)
            {
                throw new ArgumentException("start");
            }

            if (length < 0)
            {
                throw new ArgumentException("length");
            }

            if (start > range.Length)
            {
                throw new ArgumentException("start > range.Length");
            }

            if (start + length > range.Length)
            {
                throw new ArgumentException("start + length > range.Length");
            }

            _range = range;
            _start = start;
            Length = length;
        }

        public double this[int index]
        {
            get
            {
                if (index < 0 || _start + index >= _start + Length)
                {
                    throw new IndexOutOfRangeException();
                }
                return _range[_start + index];
            }
            set
            {
                if (index < 0 || _start + index >= _start + Length)
                {
                    throw new IndexOutOfRangeException();
                }
                _range[_start + index] = value;
            }
        }
    }
}