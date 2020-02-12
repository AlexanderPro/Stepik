public class Power {
    public static boolean isPowerOfTwo(int value) {
        boolean result = value == 0 ? false : ((Math.abs(value) & (Math.abs(value) - 1)) == 0);
        return result;
    }
}