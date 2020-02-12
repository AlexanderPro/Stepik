public final class ComplexNumber {
    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null) return false;

        if (obj instanceof ComplexNumber) {
            ComplexNumber number = (ComplexNumber) obj;
            return Double.doubleToLongBits(this.re) == Double.doubleToLongBits(number.re) &&
                Double.doubleToLongBits(this.im) == Double.doubleToLongBits(number.im);
        }

        return false;
    }

    @Override
    public int hashCode() {
        long h = Double.doubleToLongBits(re) + Double.doubleToLongBits(im);
        return (int) h ^ (int)(h >>> 32);
    }
}