import java.util.*;

public class SumFromInToOut {
    public static void main(String[] args) {
        double sum = 0;
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            if (scan.hasNextDouble()) {
                sum += Double.parseDouble(scan.next());
            } else {
                scan.next();
            }
        }
        System.out.printf("%.6f", sum);
    }
}