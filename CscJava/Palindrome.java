public class Palindrome {
    public static boolean isPalindrome(String text) {
        String sourceString = text.replaceAll("[^a-zA-Z0-9]", "");
        String reverseString = new StringBuilder(sourceString).reverse().toString();
        boolean result = sourceString.equalsIgnoreCase(reverseString);
        return result;
    }
}