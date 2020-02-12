public class Test {
    public static void main(String[] args) {
        System.out.println(getCallerClassAndMethodName());
        anotherMethod();
    }

    private static void anotherMethod() {
        System.out.println(getCallerClassAndMethodName());
    }

    public static String getCallerClassAndMethodName() {        
        Exception e = new Exception();
        StackTraceElement trace[] = e.getStackTrace();
        if (trace.length < 3) return null;
        return trace[2].getClassName() + "#" + trace[2].getMethodName();
    }
}