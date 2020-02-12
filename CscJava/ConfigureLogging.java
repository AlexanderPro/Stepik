import java.util.logging.*;

public class ConfigureLogging {
    private static void configureLogging() {
        Logger logger = Logger.getLogger("org.stepic.java");
        logger.setLevel(Level.ALL);
        XMLFormatter f = new XMLFormatter();
        ConsoleHandler ch = new ConsoleHandler();
        ch.setLevel(Level.ALL);
        ch.setFormatter(f);
        logger.addHandler(ch);
        logger.setUseParentHandlers(false);

        Logger loggerA = Logger.getLogger("org.stepic.java.logging.ClassA");
        loggerA.setLevel(Level.ALL);

        Logger loggerB = Logger.getLogger("org.stepic.java.logging.ClassB");
        loggerB.setLevel(Level.WARNING);
    }
}
