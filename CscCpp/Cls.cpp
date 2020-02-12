struct Cls {
	Cls(char c, double d, int i) : c(c), d(d), i(i)
	{}
private:
	char c;
	double d;
	int i;
};

struct ClsHelper {
	ClsHelper(char c, double d, int i)
	{
		this->c = c;
		this->d = d;
		this->i = i;
	}
	char c;
	double d;
	int i;
};

char &get_c(Cls &cls) {
	ClsHelper* h = reinterpret_cast<ClsHelper*>(&cls);
	char &c = h->c;
	return c;
}

double &get_d(Cls &cls) {
	ClsHelper* h = reinterpret_cast<ClsHelper*>(&cls);
	double &d = h->d;
	return d;
}

int &get_i(Cls &cls) {
	ClsHelper* h = reinterpret_cast<ClsHelper*>(&cls);
	int &i = h->i;
	return i;
}

int main()
{
	Cls cls('A', 1.5, 10);
	char ch = get_c(cls);
	double d = get_d(cls);
	int i = get_i(cls);
	return 0;
}