template<class T, class U>
void copy_n(T dest[], U source[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		dest[i] = (T)source[i];
	}
}


int main()
{
	int ints[4] = { 1, 2, 3, 4 };
	double doubles[4] = {};
	copy_n(doubles, ints, 4);
	return 0;
}