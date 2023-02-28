import java.io.BufferedReader;
import java.io.FileReader;

class Data{
    double[] cogfunc = new double[8];
    String name , type;
    double distance;
}

public class MBIT {

    public static void main(String[] args) {
        String file_name = "data.csv";
        BufferedReader br = new bufferedReader(new FileReader(file_name));
    }
}