#include <cstddef>
#include <cstring>

struct String {
	struct StringChunk
	{
		StringChunk(const char *str, size_t from) : from(from)
		{
			size = strlen(str);
			this->str = new char[size + 1];
			strcpy(this->str, str);
		}

		String operator[] (size_t to) const
		{
			char * temp = new char[to - from + 1];
			size_t index = from;
			int i = 0;
			for (; index < to; i++, index++)
			{
				temp[i] = str[index];
			}
			temp[i] = '\0';

			String result(temp);
			delete[] temp;
			return result;
		}

		~StringChunk()
		{
			delete[] str;
		}

		size_t from;
		size_t size;
		char *str;
	};

	String(const char *str = "")
	{
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);
	}

	String(size_t n, char c)
	{
		size = n;
		str = new char[n + 1];
		int i = 0;
		for (; i < n; i++)
		{
			str[i] = c;
		}
		str[i] = '\0';
	}

	String(const String &other)
	{
		size = other.size;
		str = new char[size + 1];
		strcpy(str, other.str);
	}

	String& operator=(const String &other)
	{
		if (this != &other)
		{
			delete[] str;
			size = other.size;
			str = new char[size + 1];
			strcpy(str, other.str);
		}
		return *this;
	}

	StringChunk operator[] (size_t from) const
	{
		return StringChunk(str, from);
	}

	char & at(size_t idx)       { return str[idx]; }
	char   at(size_t idx) const { return str[idx]; }

	void append(String &other)
	{
		char * temp = new char[size + 1];
		strcpy(temp, str);
		delete[] str;
		str = new char[size + other.size + 1];
		strcpy(str, temp);
		delete[] temp;
		int i = 0;
		for (; i < other.size; i++)
		{
			str[size + i] = other.str[i];
		}
		str[size + i] = '\0';
		size = strlen(str);
	}

	~String()
	{
		delete[] str;
	}

	size_t size;
	char *str;
};




int main()
{
	String s1 = "Hello world!";
    String s2(10, 'A');

	String s3("Hello,");
	String s4(" world!");
	s3.append(s4);

	String s5 = s1;
	s2 = s1;

	String hello("hello");
	String hell = hello[0][4];
	String ell = hello[1][4];

	//String s1("Hello ");
	//String s2(s1);

	//String greet("Hello");
	//char ch1 = greet.at(0);

	//String const const_greet("Hello, Const!");
	//char const &ch2 = const_greet.at(0);


	return 0;
}