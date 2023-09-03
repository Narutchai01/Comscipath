/**
 * BicycleRegistration
 */
public class BicycleRegistration {

    public static void main(String[] args) {
        Bicycle bike1, bike2;
        String owner1, owner2,tag1,tag2;

        bike1 = new Bicycle();
        bike2 = new Bicycle();

        bike1 = new Bicycle();
        bike1.setOwnerName("Adam Smith");
        bike1.setTagNo("2004-134R");

        bike2 = new Bicycle();
        bike2.setOwnerName("Ben Jones");
        bike2.setTagNo("2004-135R");

        owner1 = bike1.getOwnerName();
        tag1 = bike1.getTagNo();
        owner2 = bike2.getOwnerName();
        tag2 = bike2.getTagNo();


        System.out.println(owner1 + " owns a bicycle");
        System.out.println("Tag Number is " + tag1);
        System.out.println(owner2 + " also owns a bicycle");
        System.out.println("Tag Number is " + tag2);
    }
}