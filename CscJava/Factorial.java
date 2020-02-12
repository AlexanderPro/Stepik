import java.math.*;

public class Factorial {
    public static BigInteger factorial(int value) {
        BigInteger result = BigInteger.valueOf(1);
        if (value == 0 || value == 1) return result;
        for (int i = 2; i <= value; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
}