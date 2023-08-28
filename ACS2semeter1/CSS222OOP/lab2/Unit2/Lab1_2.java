/**
 * Lab1_2
 */
public class Lab1_2 {

    public static void main(String[] args) {
        int x = 5;
        int y = 10;
        if (x > y) {
            System.out.println(x + " is greater than " + y);
        } else {
            System.out.println(x + " is less than " + y);
        }
        char grade = 'A';

        switch (grade) {
            case 'A':
                System.out.println("Excellent!");
                break;
            case 'B':
                System.out.println("Good!");
                break;
            case 'C':
                System.out.println("Well done!");
                break;
            case 'D':
                System.out.println("You passed!");
                break;
            case 'F':
                System.out.println("Better try again!");
                break;
            default:
                System.out.println("Invalid grade!");
        }

        int a = 10;
        for (int i = 0; i < a; i++) {
            System.out.println("i = " + i);
        }
        int b = 0;
        while (b <= 5) {
            System.out.println("b = " + b);
            b++;
        }
        do {
            System.out.println("b = " + b);
            b++;
        } while (b <= 5);
    }

}