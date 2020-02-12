public class ArrayUtilities {
    public static int[] mergeArrays(int[] a1, int[] a2) {
        int[] a = new int[a1.length + a2.length];
        int i = 0, i1 = 0, i2 = 0;
        out:
            for (; i1 < a1.length; i1++) {
                for (; i2 < a2.length; i2++) {
                    if (a1[i1] <= a2[i2]) {
                        a[i++] = a1[i1];
                        continue out;
                    } else {
                        a[i++] = a2[i2];
                    }
                }
                a[i++] = a1[i1];
            }
        for (; i2 < a2.length; i2++) {
            a[i++] = a2[i2];
        }
        return a;
    }
}