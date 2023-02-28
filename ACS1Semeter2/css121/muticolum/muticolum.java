/**
 * muticolum
 */
public class muticolum {

    public static void main(String[] args) {
        int[][] number = {
                { 1, 1, 1, 4 },
                { 2, 3, 1, 1 },
                { 3, 4, 4, 4 },
                { 4, 2, 4, 4 },
                { 5, 3, 5, 3 },
                { 6, 4, 3, 3 },
                { 7, 1, 3, 3 },
                { 8, 2, 4, 3 },
                { 9, 3, 3, 5 },
                { 10, 1, 5, 3 },
                { 11, 1, 1, 4 },
                { 12, 4, 1, 1 },
                { 13, 5, 2, 3 },
                { 14, 3, 5, 2 }
        };
        // System.out.println("Before sort");
        System.out.println("COL     A       B       C");
        Printarray(number);

        System.out.println();
        sortA(number);
        System.out.println("Sortting A>B>C");
        System.out.println("COL     A       B       C");
        Printarray(number);

        System.out.println();
        sortB(number);
        System.out.println("Sortting B>C>A");
        System.out.println("COL     A       B       C");
        Printarray(number);
    };

    public static void Printarray(int[][] number) {
        for (int i = 0; i < number.length; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(number[i][j] + "\t");
            }
            System.out.println();
        }
    }

    static int[][] sortA(int[][] number) {
        for (int i = 0; i < number.length; i++) {
            for (int j = i + 1; j < number.length; j++) {
                if (number[i][1] > number[j][1] || number[i][1] == number[j][1] && number[i][2] > number[j][2]
                        || number[i][1] == number[j][1] && number[i][2] == number[j][2]
                                && number[i][3] > number[j][3]) {
                    int[] temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
            }
        }
        return number;
    }

    static int[][] sortB(int[][] number) {
        for (int i = 0; i < number.length; i++) {
            for (int j = i + 1; j < number.length; j++) {
                if (number[i][2] > number[j][2] || number[i][2] == number[j][2] && number[i][3] > number[j][3]
                        || number[i][2] == number[j][2] && number[i][3] == number[j][3]
                                && number[i][1] > number[j][1]) {
                    int[] temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
            }
        }
        return number;
    }

}
