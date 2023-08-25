public class CastingTest {
    public static void main(String[] args) {
        // create an integer number
        int  a = 9;
        // convert the integer to double
        double b = a;

        // create a double number
        double c = 9.8;
        // convert the double to integer
        int d = (int) c;

        System.out.println("Interger: " + a);
        System.out.println("After coverting to double: " + b);
        System.out.println("Double: " + c);
        System.out.println("After coverting to integer: " + d);
    }
}
