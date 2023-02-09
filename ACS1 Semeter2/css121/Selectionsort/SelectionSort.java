class Students {
    String name;
    int score;
}

class SelectionSort {
    public static void main(String[] args) {
        SelectionSort ob = new SelectionSort();
        // Students[] student = new Students[11];
        String[] nameStudent = { "Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun"};
        int[] scoreStudnet = { 90, 90, 70, 70, 85, 80, 92, 91, 82, 87};
        Students[] student = new Students[nameStudent.length];
        for (int i = 0; i < student.length; i++) {
            student[i] = new Students();
            student[i].name = nameStudent[i];
            student[i].score = scoreStudnet[i];

        }
        PrintArray(student);
        System.out.println();
        ob.sort(student);
        PrintArray(student);
    }

    static void PrintArray(Students students[]) {
        for (int i = 0; i < 10; i++) {
            System.out.println(students[i].name + " " + students[i].score);
        }
    }

    void sort(Students students[]) {
        int n = students.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (students[j].score < students[min_idx].score)
                    min_idx = j;
            }

            // Swap the found minimum element with the first
            // element
            int temp = students[min_idx].score;
            students[min_idx].score = students[i].score;
            students[i].score = temp;

            String temp2 = students[min_idx].name;
            students[min_idx].name = students[i].name;
            students[i].name = temp2;
        }
    }


}
