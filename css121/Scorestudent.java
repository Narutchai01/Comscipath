
class Students {
    String name;
    int score;
}

public class Scorestudent {
    public static void main(String[] args) {
        Students[] student = new Students[10];
        String[] nameStudent = { "Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun" };
        int[] scoreStudnet = {1,5,1,9,9,10,4,5,6,7};
        for (int i = 0; i < student.length; i++) {
            student[i] = new Students();
            student[i].name = nameStudent[i];
            student[i].score = scoreStudnet[i];

        }
        for (int i = 0; i < nameStudent.length; i++) {
            printStudent(student[i]);
        }
        Maxscore(student);
        Minscore(student);
        AvrScore(student);
        ModeScore(student);
    }

    public static void printStudent(Students student) {
        // for (int i = 0; i < 1; i++) {
        System.out.println("Name : " + student.name + " Score : " + student.score);
        // }
    }

    public static void AvrScore(Students[] student) {
        int sum = 0;
        for (int i = 0; i < student.length; i++) {
            sum += student[i].score;
        }
        int avrscore = sum / student.length;
        System.out.println("AVR IS " + avrscore);
    }

    public static void Maxscore(Students[] student) {
        int maxscore = 0;
        for (int i = 0; i < student.length; i++) {
            if (student[i].score > maxscore) {
                maxscore = student[i].score;

            }
        }
        System.out.println("Maxscore = " + maxscore);
    }

    public static void Minscore(Students[] student) {
        int minscore = 99999;
        for (int i = 0; i < student.length; i++) {
            if (student[i].score < minscore) {
                minscore = student[i].score;
            }
        }
        System.out.println("Minscore =  "+minscore);
    }
    public static void ModeScore(Students[] student){
        int cout = 0;
        for (int i = 0; i < student.length; i++) {
            for (int j = 0; j < student.length; j++) {
                if (student[i].score==student[j].score) {
                    ++cout;
                }
            }
        }
        System.out.println(cout);
    }
}
