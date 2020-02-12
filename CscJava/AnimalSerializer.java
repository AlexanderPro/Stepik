import java.io.*;

public class AnimalSerializer {

    public static byte[] serializeAnimalArray(Animal[] animals) throws IOException {
        try (ByteArrayOutputStream b = new ByteArrayOutputStream()) {
            try (ObjectOutputStream o = new ObjectOutputStream(b)) {
                o.writeInt(animals.length);
                for (Animal animal: animals) {
                    o.writeObject(animal);
                }
                return b.toByteArray();
            }
        }
    }
}