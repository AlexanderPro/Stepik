unsigned strlength(const char *str)
{
	int length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}
	return length;
}

int _strstr(const char *text, const char *pattern)
{
	if (strlength(text) == 0 && strlength(pattern) == 0) return 0;

	int index = 0;
	for (; *text; text++) {
		const char *s, *p;
		for (s = text, p = pattern; *s && *p && (*s == *p); ++s, ++p) {
		}
		if (*p == '\0') {
			return index;
		}
		index++;
	}
	return -1;
}

int main()
{
	char * s = "Hello world!";
	char * p = "world";
	int index = _strstr(s, p);

	return 0;
}