import java.util.Arrays;


class Students {
    String name;
    int score;
}

class NewScore {
    String name;
    int score;
}

class Scoreboard {
    public static void main(String[] args) {
        Students[] student = new Students[10];
        String[] nameStudent = { "Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun" };
        int[] scoreStudnet = { 90, 90, 70, 70, 85, 80, 92, 91, 82, 87 };
        for (int i = 0; i < student.length; i++) {
            student[i] = new Students();
            student[i].name = nameStudent[i];
            student[i].score = scoreStudnet[i];

        }
        PrintArray(student);
        Sort(student);
    }

    static void PrintArray(Students[] student) {
        for (int i = 0; i < student.length; i++) {
            System.out.println("Name : " + student[i].name + " Score :" + student[i].score);
        }
    }

    static void Sort(Students[] student) {
        for (int i = 0; i < student.length; i++) {
            for (int j = 0; j < student.length; j++) {
                if (student[i].score < student[j].score) {
                    student[i].score = student[j].score;
                    student[i].name = student[j].name;
                }
            }
        }
        for (int i = 0; i < student.length; i++) {
            System.out.println("Name : " + student[i].name + " Score :" + student[i].score);
        }
    }
}