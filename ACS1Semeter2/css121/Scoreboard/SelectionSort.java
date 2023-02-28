class Students {
    String name;
    int score;
}

class SelectionSort {
    public static void main(String[] args) {
        Students[] student = new Students[10];
        String[] nameStudent = { "Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun" };
        int[] scoreStudnet = { 90, 90, 70, 70, 85, 80, 92, 91, 82, 87 };
        for (int i = 0; i < student.length; i++) {
            student[i] = new Students();
            student[i].name = nameStudent[i];
            student[i].score = scoreStudnet[i];

        }
    }
    static void PrintArray(Students students[]){
        for (int i = 0; i < students.length; i++) {
            System.out.println(student[i].name+" "+student[i].score);
        }
    }
}