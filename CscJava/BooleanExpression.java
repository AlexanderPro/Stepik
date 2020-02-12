public class BooleanExpression {
    public static boolean booleanExpression(boolean a, boolean b, boolean c, boolean d) {
         boolean result = (a & b & !c & !d) || 
                          (a & !b & c & !d) ||
                          (a & !b & !c & d) ||
                          (!a & b & !c & d) ||                          
                          (!a & b & c & !d) ||         
                          (!a & !b & c & d);
         return result;
    }
}
