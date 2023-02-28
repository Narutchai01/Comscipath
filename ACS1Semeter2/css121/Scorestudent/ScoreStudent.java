import java.util.ArrayList;

class Students {
    String name;
    int score;
}

public class ScoreStudent {
    public static void main(String[] args) {
        Students[] student = new Students[10];
        String[] nameStudent = { "Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun" };
        int[] scoreStudnet = { 90, 90, 70, 70, 85, 80, 92, 91, 82, 87 };
        for (int i = 0; i < student.length; i++) {
            student[i] = new Students();
            student[i].name = nameStudent[i];
            student[i].score = scoreStudnet[i];

        }
        Maxscore(student);
        Minscore(student);
        System.out.println("AVR : " + AvrScore(student));
        ModeScore(student);
        Median(student);
        System.out.printf("SDscore : %.2f",SDscore(student));
        System.out.println(" ");
        Gradstudent(student);
    }

    static double AvrScore(Students[] student) {
        double sum = 0;
        for (int i = 0; i < student.length; i++) {
            sum += student[i].score;
        }
        double avrscore = sum / student.length;
        return avrscore;
    }

    public static void Maxscore(Students[] student) {
        int maxscore = 0;
        for (int i = 0; i < student.length; i++) {
            if (student[i].score > maxscore) {
                maxscore = student[i].score;

            }
        }
        System.out.println("Maxscore : " + maxscore);
    }

    public static void Minscore(Students[] student) {
        int minscore = 99999;
        for (int i = 0; i < student.length; i++) {
            if (student[i].score < minscore) {
                minscore = student[i].score;
            }
        }
        System.out.println("Minscore : " + minscore);
    }

    public static void ModeScore(Students[] students) {
        ArrayList<Integer> modemember = new ArrayList<Integer>();
        int maxcount = 0;
        int count = 0;

        for (int i = 0; i < students.length; i++) {
            for (int j = 0; j < students.length; j++) {
                if (students[i].score == students[j].score) {
                    count++;
                }
            }
            if (count >= maxcount) {
                maxcount = count;
                if (!modemember.contains(students[i].score)) {
                    modemember.add(students[i].score);
                }
            }
            count = 0;
        }
        for (Integer integer : modemember) {
            System.out.print(integer + " ");
        }
        System.out.println("is modenumber value : " + maxcount);
    }

    public static void Median(Students[] students) {
        int len = students.length;

        if (len % 2 == 0) {
            double mediannumber = (students[(len / 2) - 1].score + students[len / 2].score) / 2;
            System.out.println("Medianscore is : " + mediannumber);
        } else {
            System.out.println("Medianscore is : " + students[len / 2]);
        }
    }

    static double SDscore(Students[] students) {
        double x = 0;
        double xbar = 0;
        double total = 0;
        for (int i = 0; i < students.length; i++) {
            x += students[i].score;
        }
        xbar = x / students.length;
        for (int i = 0; i < students.length; i++) {
            total += Math.pow(students[i].score - xbar, 2);
        }
        total = total / (students.length - 1);
        return Math.sqrt(total);
    }

    public static void Gradstudent(Students[] students) {
        double avr = AvrScore(students);
        double sd = SDscore(students);
        for (int i = 0; i < students.length; i++) {
            if (students[i].score>avr+(2*sd)) {
                System.out.println(students[i].name+" GRAD = A");
            }else if (students[i].score<avr+(2*sd) && students[i].score>avr+sd) {
                System.out.println(students[i].name+" GRAD = B");
            }else if (students[i].score<avr+sd && students[i].score>avr) {
                System.out.println(students[i].name+" GRAD = C");
            }else if (students[i].score<avr && students[i].score>avr-sd) {
                System.out.println(students[i].name+" GRAD = D");
            }else{
                System.out.println(students[i].name+" GRAD = F");
            }
        }
    }
}