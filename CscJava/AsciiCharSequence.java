public class AsciiCharSequence implements CharSequence {
    private final byte[] array;

    public AsciiCharSequence(byte[] array) {
        this.array = array;
    }

    @Override
    public int length() {
        return array.length;
    }

    @Override
    public char charAt(int index) {
        return (char) array[index];
    }

    @Override
    public CharSequence subSequence(int start, int end) {
        return new AsciiCharSequence(java.util.Arrays.copyOfRange(array, start, end));
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(this);
        return builder.toString();
    }
}