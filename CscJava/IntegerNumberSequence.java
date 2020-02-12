import java.util.*;

public class IntegerNumberSequence {
    public static void main(String[] args) throws Exception {
        List < Integer > evenNumbers = new ArrayList < > ();

        int i = 1;
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int val = scanner.nextInt();

            if (i++ % 2 == 0) {
                evenNumbers.add(val);
            }
        }

        Collections.reverse(evenNumbers);
        evenNumbers.forEach(x -> System.out.print(x + " "));
    }
}