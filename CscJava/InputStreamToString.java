import java.io.*;
import java.nio.charset.*;

public class InputStreamToString {
    public static String readAsString(InputStream inputStream, Charset charset) throws IOException {
        StringBuilder builder = new StringBuilder();
        Reader reader = new InputStreamReader(inputStream, charset);
        int ch = 0;
        while ((ch = reader.read()) != -1) {
            builder.append(Character.toChars(ch));
        }
        return builder.toString();
    }
}