using System;

namespace Incapsulation.RationalNumbers
{
    public class Rational
    {
        public int Numerator { get; private set; }

        public int Denominator { get; private set; }

        public bool IsNan { get { return Denominator < 1; } }

        public Rational(int numerator, int denominator = 1)
        {
            Numerator = numerator;
            Denominator = denominator;
            if (Denominator < 0)
            {
                Numerator = -Numerator;
                Denominator = -Denominator;
            }
            Reduce();
        }

        private int Gcd(int numerator, int denominator)
        {
            if (numerator == 0) return denominator;
            return Gcd(denominator % numerator, numerator);
        }

        internal void Reduce()
        {
            int nod = Gcd(Numerator, Denominator);
            if (nod != 0)
            {
                Numerator = Numerator / Math.Abs(nod);
                Denominator = Denominator / Math.Abs(nod);
            }
        }

        public Rational Add(Rational rational)
        {
            var temp = new Rational(0);
            if (Denominator == rational.Denominator)
            {
                temp.Numerator = Numerator + rational.Numerator;
                temp.Denominator = Denominator;
            }
            else
            {
                temp.Denominator = Denominator * rational.Denominator;
                temp.Numerator = temp.IsNan ? 0 : (temp.Denominator / Denominator * Numerator) + (temp.Denominator / rational.Denominator * rational.Numerator);
            }
            temp.Reduce();
            return temp;
        }

        public Rational Sub(Rational rational)
        {
            var temp = new Rational(0);
            if (Denominator == rational.Denominator)
            {
                temp.Numerator = Numerator - rational.Numerator;
                temp.Denominator = Denominator;
            }
            else
            {
                temp.Denominator = Denominator * rational.Denominator;
                temp.Numerator = temp.IsNan ? 0 : (temp.Denominator / Denominator * Numerator) - (temp.Denominator / rational.Denominator * rational.Numerator);
            }
            temp.Reduce();
            return temp;
        }

        public Rational Mul(Rational rational)
        {
            var temp = new Rational(0);
            temp.Numerator = Numerator * rational.Numerator;
            temp.Denominator = Denominator * rational.Denominator;
            temp.Reduce();
            return temp;
        }

        public Rational Div(Rational rational)
        {
            var temp = new Rational(0);
            temp.Numerator = Numerator * rational.Denominator;
            temp.Denominator = Denominator * rational.Numerator;
            temp.Numerator = rational.Numerator < 0 ? -Math.Abs(temp.Numerator) : Math.Abs(temp.Numerator);
            temp.Denominator = rational.Denominator < 0 ? -Math.Abs(temp.Denominator) : Math.Abs(temp.Denominator);
            if (rational.Denominator == 0)
            {
                temp.Denominator = 0;
            }
            temp.Reduce();
            return temp;
        }

        public static Rational operator +(Rational r1, Rational r2)
        {
            return r1.Add(r2);
        }

        public static Rational operator -(Rational r1, Rational r2)
        {
            return r1.Sub(r2);
        }

        public static Rational operator *(Rational r1, Rational r2)
        {
            return r1.Mul(r2);
        }

        public static Rational operator /(Rational r1, Rational r2)
        {
            return r1.Div(r2);
        }

        public static explicit operator int(Rational r)
        {
            if (r.Numerator % r.Denominator != 0)
            {
                throw new Exception();
            }

            return r.Numerator;
        }

        public static implicit operator double(Rational r)
        {
            return r.Denominator == 0 ? double.NaN : (double)r.Numerator / r.Denominator;
        }

        public static implicit operator Rational(int n)
        {
            return new Rational(n);
        }
    }
}