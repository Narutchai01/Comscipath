
public class Hero2 {

    void printArray(int arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Hero2 ob = new Hero2();
        int n = 10;
        int[] tree = { (int) (Math.random() * 10), (int) (Math.random() * 10) };
        int birtday = 2, last = 0, slast = 4; // เกิดวัน 2 เลขสุดท้ายของid 0 เลขรองสุดท้ายของ id 4
        int[][] map = new int[n][n];
        int Taxicab = Math.abs(last - birtday) + Math.abs(slast - (10 - birtday));
        double Euclidean = Math.sqrt(Math.pow(last - birtday, 2) + Math.pow(slast - (10 - birtday), 2));
        int Chebyshev;
        Chebyshev = (5 > 10) ? Math.abs(last - birtday) : Math.absExact(slast - (10 - birtday));

        map[tree[0]][tree[1]] = 1; // tree
        map[birtday][last] = 2; // hero
        map[10 - birtday][slast] = 3; // monster
        // ob.swippingelement(map);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int temp = map[i][j];
                map[i][j] = map[j][n - i - 1];
                map[j][n - i - 1] = map[n - i - 1][n - j - 1];
                map[n - i - 1][n - j - 1] = map[n - j - 1][i];
                map[n - j - 1][i] = temp;
            }
        }
        ob.printArray(map);
        System.out.println("\nTaxicab distance = " + Taxicab);
        System.out.printf("Euclidean distance = %.1f", Euclidean);
        System.out.println("\nChebyshev distance = " + Chebyshev);
    }
}
