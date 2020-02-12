import java.io.*;

public class AnimalDeserializer {

    public static Animal[] deserializeAnimalArray(byte[] data) throws IOException, ClassNotFoundException {
        try (ByteArrayInputStream b = new ByteArrayInputStream(data)) {
            try (ObjectInputStream o = new ObjectInputStream(b)) {
                int length = o.readInt();
                Animal[] animals = new Animal[length];
                for (int i = 0; i < length; i++) {
                    animals[i] = (Animal) o.readObject();
                }
                return animals;
            }
        } catch (Exception e) {
            throw new java.lang.IllegalArgumentException();
        }
    }
}