import java.util.*;

public class SetDifference {
    public static < T > Set < T > symmetricDifference(Set < ? extends T > set1, Set < ? extends T > set2) {
        Set < T > set = new HashSet < > ();
        set.addAll(set1);
        set.addAll(set2);

        Iterator < T > it = set.iterator();
        while (it.hasNext()) {
            T item = it.next();
            if (set1.contains(item) && set2.contains(item)) {
                it.remove();
            }
        }

        return set;
    }
}