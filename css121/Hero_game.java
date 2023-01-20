
/**
 * Bonus
 */

// hero x = 2 y = 0
// monster x 10-2 y = 4
public class Hero_game {

    public static void main(String[] args) {
        int n = 10;
        int[][] map = new int[n][n];
        int[] tree = { (int) (Math.random() * 10), (int) (Math.random() * 10) };
        int birtday = 2, last = 0, slast = 4; //เกิดวัน 2 เลขสุดท้ายของid 0 เลขรองสุดท้ายของ id 4

        int Taxicab = Math.abs(last-birtday)+Math.abs(slast-(10-birtday));
        double Euclidean = Math.sqrt(Math.pow(last-birtday, 2)+Math.pow(slast-(10-birtday), 2));
        int Chebyshev;
        Chebyshev = (5>10) ? Math.abs(last-birtday) : Math.absExact(slast-(10-birtday));

        map[tree[0]][tree[1]] = 1; //tree
        map[birtday][last] = 2; //hero
        map[10 - birtday][slast] = 3; //monster

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int temp = map[i][j];
                map[i][j] = map[j][n - i - 1];
                map[j][n - i - 1] = map[n - i - 1][n - j - 1];
                map[n - i - 1][n - j - 1] = map[n - j - 1][i];
                map[n - j - 1][i] = temp;
            }
        }
        // สร้าง metrix ขนาด 10*10

        for (int i = 0; i < n; i++) {
            System.out.println();
            for (int j = 0; j < n; j++) {
                System.out.print(map[i][j]+" ");

            }
        }
        System.out.println();
        System.out.println("\nTaxicab distance = "+Taxicab);
        System.out.printf("Euclidean distance = %.1f",Euclidean);
        System.out.println("\nChebyshev distance = "+Chebyshev);
        
    }

}