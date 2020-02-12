class Pair < T1, T2 > {
    private final T1 value1;
    private final T2 value2;

    private Pair(T1 value1, T2 value2) {
        this.value1 = value1;
        this.value2 = value2;
    }

    public static < T1,
    T2 > Pair < T1,
    T2 > of(T1 value1, T2 value2) {
        return new Pair < T1, T2 > (value1, value2);
    }

    public T1 getFirst() {
        return value1;
    }

    public T2 getSecond() {
        return value2;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Pair)) {
            return false;
        }
        Pair < ? , ? > p = (Pair < ? , ? > ) obj;
        return java.util.Objects.equals(p.getFirst(), getFirst()) && java.util.Objects.equals(p.getSecond(), getSecond());
    }

    @Override
    public int hashCode() {
        return java.util.Objects.hash(this.value1, this.value2);
    }
}