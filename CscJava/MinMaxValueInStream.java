import java.util.*;
import java.util.stream.*;
import java.util.function.*;

public class MinMaxValueInStream {
    public static < T > void findMinMax(
        Stream < ? extends T > stream,
        Comparator < ? super T > order,
        BiConsumer < ? super T, ? super T > minMaxConsumer) {

        MinMaxFinder < T > minMaxFinder = new MinMaxFinder < > (order);
        stream.forEach(minMaxFinder);
        minMaxConsumer.accept(minMaxFinder.min, minMaxFinder.max);
    }


    private static class MinMaxFinder < T > implements Consumer < T > {

        private final Comparator < ? super T > order;
        T min;
        T max;

        private MinMaxFinder(Comparator < ? super T > order) {
            this.order = order;
        }

        @Override
        public void accept(T t) {
            if (min == null || order.compare(t, min) < 0) {
                min = t;
            }
            if (max == null || order.compare(max, t) < 0) {
                max = t;
            }
        }
    }
}