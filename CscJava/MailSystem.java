import java.util.logging.*;

public class MailSystem {

    public static void main(String[] args) {
    }

    public static final String AUSTIN_POWERS = "Austin Powers";
    public static final String WEAPONS = "weapons";
    public static final String BANNED_SUBSTANCE = "banned substance";

    public static class UntrustworthyMailWorker implements MailService {
        private RealMailService realMailService;
        private MailService[] mailServices;

        public UntrustworthyMailWorker(MailService[] mailServices) {
            this.mailServices = mailServices;
            for (MailService ms : this.mailServices) {
                if (ms instanceof RealMailService)
                    this.realMailService = (RealMailService)ms;
            }
            if (this.realMailService == null) {
                this.realMailService = new RealMailService();
            }
        }

        @Override
        public Sendable processMail(Sendable mail) {
            Sendable m = mail;
            for (MailService ms : this.mailServices) {
                if (ms instanceof RealMailService)
                    continue;
                m = ms.processMail(m);
            }
            if (getRealMailService() != null) {
                m = this.realMailService.processMail(m);
            }
            return m;
        }

        public RealMailService getRealMailService() {
            return realMailService;
        }
    }

    public static class Spy implements MailService {
        private Logger logger;

        public Spy(Logger logger) {
            this.logger = logger;
        }

        @Override
        public Sendable processMail(Sendable mail) {
            if (mail instanceof MailMessage) {
                MailMessage ms = (MailMessage)mail;
                if (ms.getFrom().equals(AUSTIN_POWERS) || ms.getTo().equals(AUSTIN_POWERS)) {
                    logger.log(Level.WARNING, "Detected target mail correspondence: from {0} to {1} \"{2}\"",
                            new Object[] { ms.getFrom(), ms.getTo(), ms.getMessage() });
                } else {
                    logger.log(Level.INFO, "Usual correspondence: from {0} to {1}",
                            new Object[] { ms.getFrom(), ms.getTo() });
                }
            }
            return mail;
        }
    }

    public static class Inspector implements MailService {
        @Override
        public Sendable processMail(Sendable mail) {
            if (mail instanceof MailPackage) {
                MailPackage mp = (MailPackage) mail;
                if (mp.getContent().content.contains(WEAPONS)
                        || mp.getContent().content.contains(BANNED_SUBSTANCE)) {
                    throw new IllegalPackageException();
                } else if (mp.getContent().content.contains("stones")) {
                    throw new StolenPackageException();
                }
            }
            return mail;
        }
    }

    public static class Thief implements MailService {
        private int minPrice = 0;
        private int stolenValue = 0;

        public Thief(int minPrice) {
            this.minPrice = minPrice;
        }

        public int getStolenValue() {
            return stolenValue;
        }

        @Override
        public Sendable processMail(Sendable mail) {
            if (mail instanceof MailPackage) {
                MailPackage mp = (MailPackage)mail;
                if (mp.content.price >= minPrice) {
                    this.stolenValue += mp.content.price;
                    return new MailPackage(mail.getFrom(), mail.getTo(), new Package("stones instead of " + mp.content.getContent(), 0));
                }
            }
            return mail;
        }
    }

    public static class StolenPackageException extends java.lang.RuntimeException {

    }

    public static class IllegalPackageException extends java.lang.RuntimeException {

    }

    public static interface Sendable {
        String getFrom();
        String getTo();
    }

    public static abstract class AbstractSendable implements Sendable {

        protected final String from;
        protected final String to;

        public AbstractSendable(String from, String to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public String getFrom() {
            return from;
        }

        @Override
        public String getTo() {
            return to;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            AbstractSendable that = (AbstractSendable) o;

            if (!from.equals(that.from)) return false;
            if (!to.equals(that.to)) return false;

            return true;
        }

    }

    public static class MailMessage extends AbstractSendable {

        private final String message;

        public MailMessage(String from, String to, String message) {
            super(from, to);
            this.message = message;
        }

        public String getMessage() {
            return message;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            if (!super.equals(o)) return false;

            MailMessage that = (MailMessage) o;

            if (message != null ? !message.equals(that.message) : that.message != null) return false;

            return true;
        }

    }

    public static class MailPackage extends AbstractSendable {
        private final Package content;

        public MailPackage(String from, String to, Package content) {
            super(from, to);
            this.content = content;
        }

        public Package getContent() {
            return content;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            if (!super.equals(o)) return false;

            MailPackage that = (MailPackage) o;

            if (!content.equals(that.content)) return false;

            return true;
        }

    }

    public static class Package {
        private final String content;
        private final int price;

        public Package(String content, int price) {
            this.content = content;
            this.price = price;
        }

        public String getContent() {
            return content;
        }

        public int getPrice() {
            return price;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Package aPackage = (Package) o;

            if (price != aPackage.price) return false;
            if (!content.equals(aPackage.content)) return false;

            return true;
        }
    }

    public static interface MailService {
        Sendable processMail(Sendable mail);
    }

    public static class RealMailService implements MailService {

        @Override
        public Sendable processMail(Sendable mail) {
            return mail;
        }
    }

}