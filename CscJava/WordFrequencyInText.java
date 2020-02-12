import java.util.*;
import java.io.*;
import java.util.stream.*;
import java.util.function.*;
import java.nio.charset.*;

public class WordFrequencyInText {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
        Arrays.
        asList(reader.readLine().toLowerCase().split("[^\\p{L}\\p{Digit}]+")).
        stream().
        collect(Collectors.groupingBy(Function.identity(), Collectors.counting())).
        entrySet().
        stream().
        sorted(Map.Entry.<String, Long>comparingByKey()).
        sorted(Map.Entry.<String, Long>comparingByValue().reversed()).
        limit(10).
        forEachOrdered(e -> System.out.println(e.getKey()));
    }
}
