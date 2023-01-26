
public class Median {
    public static void main(String[] args) {

        int[] number = {1,2,3,4,5,6,7,8,9,10};
        int lennum = number.length;


        if (lennum%2==0){
            double mediannumber =  (number[(lennum/2)-1] + number[lennum/2])/2 ;
            System.out.println(mediannumber);
        }else{
            System.out.println(number[lennum/2]);
        }
    }
}
