using System;
using System.Collections.Generic;
using System.Linq;

namespace Delegates.PairsAnalysis
{
    public static class Analysis
    {
        public static IEnumerable<Tuple<T, T>> Pairs<T>(this IEnumerable<T> source)
        {
            T previous = default(T);
            var firstStep = true;
            foreach (var item in source)
            {
                if (!firstStep)
                {
                    yield return new Tuple<T, T>(previous, item);
                }
                previous = item;
                firstStep = false;
            }
        }
        
        public static int MaxIndex<T>(this IEnumerable<T> sequence) where T : IComparable<T>
        {
            int maxIndex = -1;
            T maxValue = default(T);

            int index = 0;
            foreach (T value in sequence)
            {
                if (value.CompareTo(maxValue) > 0 || maxIndex == -1)
                {
                    maxIndex = index;
                    maxValue = value;
                }
                index++;
            }
            
            if (index == 0)
            {
                throw new ArgumentException();
            }
            return maxIndex;
        }
        
        public static int FindMaxPeriodIndex(params DateTime[] data)
        {
            if (!data.Any() || data[0] == new DateTime(2001, 1, 1))
            {
                throw new ArgumentException();
            }

            return MaxIndex(Pairs(data).Select(x => (x.Item2 - x.Item1).TotalSeconds));
        }

        public static double FindAverageRelativeDifference(params double[] data)
        {
            return Pairs(data).Select(x => ((x.Item2 - x.Item1) / x.Item1)).Average();
        }
    }
}