import java.io.*;

public class EndLineWindowsToUnix {
    public static void main(String[] args) throws IOException {
        ByteArrayOutputStream buffer = new ByteArrayOutputStream();
        int nRead;
        byte[] data = new byte[1024];
        while ((nRead = System.in.read(data, 0, data.length)) != -1) {
            buffer.write(data, 0, nRead);
        }
        buffer.flush();
        byte[] byteArray = buffer.toByteArray();
        for (int i = 0; i < byteArray.length; i++) {
            if (byteArray[i] == 13 && ((i + 1) < byteArray.length) && byteArray[i + 1] == 10) {
                continue;
            } else {
                System.out.write(byteArray[i]);
            }
        }
        System.out.flush();
    }
}