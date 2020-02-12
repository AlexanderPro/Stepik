import java.util.*;
import java.util.function.*;

public class MailService<T> implements Consumer<Sendable<T>> {
    private final Map<String, List<T>> mailBox;

    public MailService() {
        mailBox = new MyHashMap<>();
    }

    public Map<String, List<T>> getMailBox() {
        return mailBox;
    }

    @Override
    public Consumer<Sendable<T>> andThen(Consumer<? super Sendable<T>> after) {
        return null;
    }

    @Override
    public void accept(Sendable<T> tSendable) {
        List<T> content = mailBox.get(tSendable.getTo());
        content.add(tSendable.getContent());
        mailBox.put(tSendable.getTo(), content);
    }
}