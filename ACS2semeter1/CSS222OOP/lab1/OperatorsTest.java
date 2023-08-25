public class OperatorsTest {
    public static void main(String[] args) {
        int a = 9;
        int b = 9;

        int result_add = a + b;
        System.out.println("a + b = " + result_add);
        ++result_add;
        System.out.println("++result_add = " + result_add);

        double result_mod = result_add % b;
        System.out.println("result_add % b = " + result_mod);

        a += 5;
        System.out.println("result of varaible a ="+a);
        System.out.println("Birwise of 2 | 1 = "+(2|1));
        boolean compare = (a == b);
        System.out.println("compare a and b " + compare);
        
        boolean logical = (a<5 && b<8);
        System.out.println("logical a and b " + logical);
    }
}
