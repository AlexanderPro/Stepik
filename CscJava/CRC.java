import java.io.*;

public class CRC {
    public static int checkSumOfStream(InputStream inputStream) throws IOException {
        ByteArrayOutputStream buffer = new ByteArrayOutputStream();
        int nRead;
        byte[] data = new byte[1024];
        while ((nRead = inputStream.read(data, 0, data.length)) != -1) {
            buffer.write(data, 0, nRead);
        }
        buffer.flush();
        byte[] byteArray = buffer.toByteArray();
        int crc = 0;
        for (int i = 0; i < byteArray.length; i++) {
            int element = Byte.toUnsignedInt(byteArray[i]);
            crc = Integer.rotateLeft(crc, 1) ^ element;
        }
        return crc;
    }
}