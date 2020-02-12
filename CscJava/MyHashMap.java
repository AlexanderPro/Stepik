import java.util.*;

public class MyHashMap<V> extends HashMap<String, List<V>> {
    @Override
    public List<V> get(Object key) {
        return this.getOrDefault(key, new LinkedList<>());
    }
}