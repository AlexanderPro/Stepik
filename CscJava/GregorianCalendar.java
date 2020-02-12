public class GregorianCalendar {
    public static int leapYearCount(int year) {
        int result = year / 4 - year / 100 + year / 400;
        return result;
    }
}