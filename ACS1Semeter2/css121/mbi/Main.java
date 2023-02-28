import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Data {
    public float[] cogFunc;
    public String type;
    public float distance;

    public Data() {
        cogFunc = new float[8];
    }
}

public class Main {
    public static void main(String[] args) {
        final String fileName = "data.csv";
        final int dataNum = 49;
        float[] userCogFunc = { 33.2f, 27f, 32f, 28f, 33f, 32f, 39f, 40f };

        Data[] data = new Data[dataNum];
        Data tempData;
        BufferedReader br = null;
        String row;
        int rowNum = 0;

        // read and store csv file in an array
        try {
            br = new BufferedReader(new FileReader(fileName));
            while ((row = br.readLine()) != null) {
                String[] items = row.split(",");
                tempData = new Data();

                for (int i = 0; i < 8; i++) {
                    tempData.cogFunc[i] = Float.parseFloat(items[i]);
                }

                tempData.type = items[8];
                data[rowNum] = tempData;
                rowNum++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        // calculate distance and assign into each struct
        for (int i = 0; i < dataNum; i++) {
            data[i].distance = findDistance(data[i], userCogFunc);
        }

        selectionSort(data, 3, dataNum);

        for (int i = 0; i < 4; i++) {
            System.out.print(findMajority(data, 3, i));
        }

        System.out.println();
    }

    public static void printData(Data[] data, int dataNum) {
        for (int i = 0; i < dataNum; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(data[i].cogFunc[j] + "\t");
            }
            System.out.print(data[i].type + "\t");
            System.out.println(data[i].distance);
        }
    }

    public static float findDistance(Data data, float[] userData) {
        float sum = 0;
        for (int i = 0; i < 8; i++) {
            sum += Math.pow(data.cogFunc[i] - userData[i], 2);
        }

        return (float) Math.sqrt(sum);
    }

    public static void selectionSort(Data[] data, int k, int dataNum) {
        int i, j, min_idx;
        for (i = 0; i < k; i++) {
            min_idx = i;
            for (j = i + 1; j < dataNum; j++) {
                if (data[j].distance < data[min_idx].distance) {
                    min_idx = j;
                }
            }

            // Swap the found minimum element with the first element
            if (min_idx != i) {
                Data temp = data[min_idx];
                data[min_idx] = data[i];
                data[i] = temp;
            }
        }
    }

    // Boyer-Moore Majority Voting
    public static char findMajority(Data[] data, int voteNum, int index) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < voteNum; i++) {
            if (count == 0) {
                res = i;
                count = 1;
            } else if (data[res].type.charAt(index) == data[i].type.charAt(index)) {
                count++;
            } else {
                count--;
            }
        }
        return data[res].type.charAt(index);
    }
}
