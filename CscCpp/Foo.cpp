#include <iostream>

struct Foo {
	void say() const 
	{ 
		std::cout << "Foo says: " << msg << "\n"; 
	}
protected:
	Foo(const char *msg) : msg(msg) 
	{ 
	}
private:
	const char *msg;
};

struct FooDerived : Foo
{
	FooDerived(const char *msg) : Foo(msg)
	{
	}
};

void foo_says(const Foo &foo) 
{ 
	foo.say(); 
}

Foo get_foo(const char *msg) 
{
	FooDerived fd(msg);
	return fd;
}

int main()
{
	foo_says(get_foo("Hello!"));
	return 0;
}