#include <iostream>

struct Rational
{
	Rational(int numerator = 0, int denominator = 1)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	void add(Rational rational)
	{
		Rational temp;

		if (denominator_ == rational.denominator_)
		{
			temp.numerator_ = numerator_ + rational.numerator_;
			temp.denominator_ = denominator_;
		}
		else
		{
			temp.denominator_ = denominator_ * rational.denominator_;
			temp.numerator_ = (temp.denominator_ / denominator_ * numerator_) + (temp.denominator_ / rational.denominator_ * rational.numerator_);
		}
		temp.reduce();

		numerator_ = temp.numerator_;
		denominator_ = temp.denominator_;
	}

	void sub(Rational rational)
	{
		Rational temp;

		if (denominator_ == rational.denominator_)
		{
			temp.numerator_ = numerator_ - rational.numerator_;
			temp.denominator_ = denominator_;
		}
		else
		{
			temp.denominator_ = denominator_ * rational.denominator_;
			temp.numerator_ = (temp.denominator_ / denominator_ * numerator_) - (temp.denominator_ / rational.denominator_ * rational.numerator_);
		}
		temp.reduce();

		numerator_ = temp.numerator_;
		denominator_ = temp.denominator_;
	}

	void mul(Rational rational)
	{
		Rational temp;
		temp.numerator_ = numerator_ * rational.numerator_;
		temp.denominator_ = denominator_ * rational.denominator_;
		temp.reduce();

		numerator_ = temp.numerator_;
		denominator_ = temp.denominator_;
	}

	void div(Rational rational)
	{
		Rational temp;
		temp.numerator_ = numerator_ * rational.denominator_;
		temp.denominator_ = denominator_ * rational.numerator_;
		temp.reduce();

		numerator_ = temp.numerator_;
		denominator_ = temp.denominator_;
	}

	void neg()
	{
		numerator_ = -numerator_;
	}

	void inv()
	{

	}

	double to_double() const
	{
		return (double)numerator_ / denominator_;
	}

	Rational operator - () const {
		return Rational(-(this->numerator_), this->denominator_);
	}

	Rational operator + () const {
		return *this;
	}

	Rational& operator += (Rational const& rational) {
		this->add(rational);
		return *this;
	}

	Rational& operator -= (Rational const& rational) {
		this->sub(rational);
		return *this;
	}

	Rational& operator *= (Rational const& rational) {
		this->mul(rational);
		return *this;
	}

	Rational& operator /= (Rational const& rational) {
		this->div(rational);
		return *this;
	}

	operator double() const {
		double result = this->to_double();
		return result;
	}

	friend bool operator < (Rational r1, Rational r2);
	friend bool operator > (Rational r1, Rational r2);
	friend bool operator == (Rational r1, Rational r2);
	friend bool operator != (Rational r1, Rational r2);
	friend bool operator <= (Rational r1, Rational r2);
	friend bool operator >= (Rational r1, Rational r2);

private:
	int numerator_;
	unsigned denominator_;

	int gcd(int a, int b)
	{
		if (a == 0) return b;
		return gcd(b%a, a);
	}

	void reduce()
	{
		int nod = gcd(numerator_, denominator_);
		numerator_ = numerator_ / nod;
		denominator_ = denominator_ / nod;
	}
};

Rational operator + (Rational r1, Rational r2) {
	Rational result = r1;
	r1.add(r2);
	return r1;
}

Rational operator - (Rational r1, Rational r2) {
	Rational result = r1;
	r1.sub(r2);
	return r1;
}

Rational operator * (Rational r1, Rational r2) {
	Rational result = r1;
	r1.mul(r2);
	return r1;
}

Rational operator / (Rational r1, Rational r2) {
	Rational result = r1;
	r1.div(r2);
	return r1;
}

bool operator < (Rational r1, Rational r2) {
	return r1.numerator_ * (int)r2.denominator_ < r2.numerator_ * (int)r1.denominator_;
}

bool operator >(Rational r1, Rational r2) {
	return r1.numerator_ * (int)r2.denominator_ > r2.numerator_ * (int)r1.denominator_;
}

bool operator == (Rational r1, Rational r2) {
	return r1.numerator_ == r2.numerator_ && r1.denominator_ == r2.denominator_;
}

bool operator != (Rational r1, Rational r2) {
	return !(r1 == r2);
}

bool operator <= (Rational r1, Rational r2) {
	return (r1 < r2) || (r1 == r2);
}

bool operator >= (Rational r1, Rational r2) {
	return (r1 > r2) || (r1 == r2);
}

int main()
{
	Rational r1(1, 3);
	Rational r2(2, 3);
	Rational r3 = r1 + r2;
	bool b = r1 < r2;
	double d = (double)r2;
	return 0;
}