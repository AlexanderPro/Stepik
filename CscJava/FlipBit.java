public class FlipBit {
    public static int flipBit(int value, int bitIndex) {
        return value ^ (1 << bitIndex - 1);
    }
}