import java.util.function.*;

public class Integral {
    public static double integrate(DoubleUnaryOperator f, double a, double b) {
        double result = 0;
        double h = 0.000001;
        double n = (b - a) / h;
        for (int i = 0; i < n; i++) {
            result += f.applyAsDouble(a + h * (i + 0.5));
        }
        result *= h;
        return result;
    }
}