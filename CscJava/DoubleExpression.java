public class DoubleExpression {
    public static boolean doubleExpression(double a, double b, double c) {
        boolean result = Math.abs(c - (a + b)) < 0.0001;
        return result;
    }
}
