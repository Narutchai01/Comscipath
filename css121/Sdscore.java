
public class Sdscore {
    public static void main(String[] args) {
        int[] number = { 16,15,20,26,17};
        double x = 0;
        double total = 0;
        for (int i = 0; i < number.length; i++) {
            x += number[i];
        }
        System.out.println(x);
        double xbar = x / number.length;
        System.out.println("Xbar : " + xbar);
        for (int i = 0; i < number.length; i++) {
            total += Math.pow(number[i] - xbar, 2);
        }
        System.out.println(total);
        total = total/(number.length-1);
        System.out.println(Math.sqrt(total));
    }
}
