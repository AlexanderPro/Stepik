class A
{
    private int x;

    public A()
    {
    }

    public static A operator +(A a1, A a2)
    {
        return new A { x = a1.x + a2.x };
    }

    public static A operator *(A a1, string a2)
    {
        return new A { x = a1.x * a2.Length };
    }

    public static implicit operator int(A a)
    {
        return a.x;
    }
}