#include <string>

struct Character
{
	std::string const & name() const;
	unsigned health() const;
};

struct LongRange : Character
{
	std::string const & name() const;
	unsigned health() const;
	unsigned range() const;
};

struct SwordsMan : Character
{
	std::string const & name() const;
	unsigned health() const;
	unsigned strength() const;
};

struct Wizard : LongRange
{
	std::string const & name() const;
	unsigned health() const;
	unsigned range() const;
	unsigned mana() const;
};

struct Archer : LongRange
{
	std::string const & name() const;
	unsigned health() const;
	unsigned range() const;
	unsigned accuracy() const;
};

int main()
{
	return 0;
}