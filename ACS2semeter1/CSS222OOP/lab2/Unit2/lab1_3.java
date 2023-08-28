import java.util.Arrays;

public class lab1_3 {
    public static void main(String[] args) {
        int a1[] = new int[10];
        int a2[] = { 3, 5, 7, 1, 8, 99, 44, -10 };
        int a3[] = { 4, 3, 2, 1 };

        System.out.println("Length of a1 is " + a1.length);
        System.out.println("Length of a2 is " + a2.length);
        System.out.println("Length of a3 is " + a3.length);

        int a4[][] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

        for (int i = 0; i < a4.length; i++) {
            for (int j = 0; j < a4[i].length; j++) {
                System.out.print(a4[i][j] + " ");
            }
            System.out.println();
        }

        int arr[] = { 234, 6, 846, 85, 96, 198, 545, 12, 60, 34, 4, 87, 7, 1 };
        Arrays.sort(arr);

        System.out.println("Sorted array is: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        

    }

}