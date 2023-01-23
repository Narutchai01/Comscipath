
/**
 * Selection
 */
import java.io.*;

public class Selection {

    void sort(int arr[]) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    }

    public static void main(String[] args) {

        Selection ob = new Selection();
        System.out.println("Seclection Sort");
        int arr[] = { 2, 5, 4, 8, 1, 80 };
        ob.sort(arr);
        ob.printArray(arr);
    }
}