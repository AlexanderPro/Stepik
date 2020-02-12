#include <string>
#include <iostream>
#include <map>
using namespace std;


struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() { }
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * vistitor) const = 0;
	virtual ~Expression(){}
};

struct Number : Expression
{
	Number(double value) : value(value)
	{}

	void visit(Visitor * visitor) const { visitor->visitNumber(this); }

	double evaluate() const
	{
		return value;
	}

	double get_value() const { return value; }

	~Number() {}

private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right) : left(left), op(op), right(right)
	{ }

	void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

	double evaluate() const
	{
		if (op == '+') return left->evaluate() + right->evaluate();
		if (op == '-') return left->evaluate() - right->evaluate();
		if (op == '*') return left->evaluate() * right->evaluate();
		if (op == '/') return left->evaluate() / right->evaluate();

		return -1;
	}

	Expression const * get_left()  const { return left; }

	Expression const * get_right() const { return right; }

	char get_op() const { return op; }

	~BinaryOperation()
	{
		delete left;
		delete right;
	}

private:
	Expression const * left;
	Expression const * right;
	char op;
};

struct PrintVisitor : Visitor {
	void visitNumber(Number const * number)
	{
		cout << number->get_value() << " ";
	}

	void visitBinaryOperation(BinaryOperation const * bop)
	{
		if (bop->get_op() == '+' || bop->get_op() == '-')
		{
			cout << "(" << " ";
			bop->get_left()->visit(this);
			cout << bop->get_op() << " ";
			bop->get_right()->visit(this);
			cout << ")" << " ";
		}

		if (bop->get_op() == '*' || bop->get_op() == '/')
		{
			bop->get_left()->visit(this);
			cout << bop->get_op() << " ";
			bop->get_right()->visit(this);
		}
	}

	~PrintVisitor(){}
};

bool check_equals(Expression const *left, Expression const *right)
{
	return *((int*)left) == *((int*)right);
}

struct ScopedPtr
{
	explicit ScopedPtr(Expression *ptr = 0)
	{
		ptr_ = ptr;
	}

	void reset(Expression *ptr = 0)
	{
		delete ptr_;
		ptr_ = ptr;
	}

	Expression* release()
	{
		Expression* temp = ptr_;
		ptr_ = 0;
		return temp;
	}

	Expression& operator*() const
	{
		return *ptr_;
	}

	Expression* operator->() const
	{
		return ptr_;
	}

	Expression* get() const
	{
		return ptr_;
	}

	~ScopedPtr()
	{
		delete ptr_;
	}

private:
	ScopedPtr(const ScopedPtr&);
	ScopedPtr& operator=(const ScopedPtr&);

	Expression *ptr_;
};


struct SharedPtr
{
	SharedPtr(Expression *ptr = 0)
	{
		ptr_ = ptr;
		if (ptr == NULL) return;
		if (counters.count(ptr) == 0)
		{
			counters.insert(pair<Expression*, unsigned int>(ptr, 1));
		}
		else
		{
			counters[ptr]++;
		}
	}

	SharedPtr(SharedPtr const& ptr)
	{
		ptr_ = ptr.ptr_;

		if (ptr.ptr_ != NULL)
		{
			counters[ptr.ptr_]++;
		}
	}

	void reset(Expression *ptr = 0)
	{
		if (ptr_ != NULL)
		{
			if (--counters[ptr_] <= 0)
			{
				delete ptr_;
				counters.erase(ptr_);
			}
		}
		if (ptr != NULL)
		{
			counters[ptr]++;
		}
		ptr_ = ptr;
	}

	Expression& operator*() const
	{
		return *ptr_;
	}

	Expression* operator->() const
	{
		return ptr_;
	}

	Expression* get() const
	{
		return ptr_;
	}

	SharedPtr& operator=(SharedPtr const& ptr)
	{
		if (this != &ptr && ptr_ != ptr.ptr_)
		{
			if (ptr_ != NULL)
			{
				if (--counters[ptr_] <= 0)
				{
					delete ptr_;
					counters.erase(ptr_);
				}
			}
			if (ptr.ptr_ != NULL)
			{
				counters[ptr.ptr_]++;
			}
			ptr_ = ptr.ptr_;
		}
		return *this;
	}

	~SharedPtr()
	{
		if (--counters[ptr_] <= 0)
		{
			delete ptr_;
			counters.erase(ptr_);
		}
	}

	Expression *ptr_;

private:
	static std::map<Expression*, int> counters;
};

std::map<Expression*, int> SharedPtr::counters;

int main()
{
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;

	Number* num1 = new Number(5);
	Number* num2 = new Number(7);
	Expression * mul = new BinaryOperation(num1, '*', num2);
	bool r1 = check_equals(num1, num2);
	bool r2 = check_equals(num1, mul);
	
	PrintVisitor visitor;
	expr->visit(&visitor);

	ScopedPtr* ptr = new ScopedPtr(sube);
	Expression* copy = ptr->release();

	SharedPtr ptr1(sube);
	SharedPtr ptr2(sube);
	SharedPtr ptr3(num1);
	ptr1 = ptr3;
	ptr3.reset(NULL);

	return 0;
}