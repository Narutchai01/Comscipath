import java.util.Arrays;

class Moddemember {
    int member;
    int mcount;
}

public class Arraylist {
    public static void main(String[] args) {
        int[] score = { 1,3,4,1 };

        int maxcount = 0;
        int count = 0;
        // int[] modenumber = new int[score.length];
        Moddemember[] moddemembers = new Moddemember[score.length];

        Arrays.sort(score);
        for (int i = 0; i < moddemembers.length; i++) {
            for (int j = 0; j < moddemembers.length; j++) {
                if (score[i] == score[j]) {
                    count++;
                }
            }
            
            if (count>maxcount) {
                maxcount = count;
                // moddemembers[i].mcount = count;
                // moddemembers[i].member = score[i];    
            }
            count = 0;
            System.out.println(maxcount);
            // System.out.println(Moddemember[i].mcount);
        }
    }
}