class animal {
    String name;
    int age;
    String sound;
    String eat;

    animal() {
    }

    animal(String name, int age, String sound, String eat) {
        this.age = age;
        this.name = name;
        this.sound = sound;
        this.eat = eat;

    }

    public int GetAge() {
        return this.age;
    }

    public String GetName() {
        return this.name;
    }

    public String GetSound() {
        return this.sound;
    }

    public String GetEat() {
        return this.eat;
    }
}

class mammal extends animal {

    mammal() {
    }

    mammal(String name, int age, String sound, String eat) {
        super(name, age, sound, eat);
    }

    public String makeSound() {
        return this.sound;
    }

}

class bird extends animal {

    bird() {
    }

    bird(String name, int age, String sound, String eat) {
        super(name, age, sound, eat);
    }

    public String makeSound() {
        return this.sound;
    }

}

public class App {
    public static void main(String[] args) throws Exception {
        mammal m = new mammal("Dog", 20000, "Bahhhhhhhh", "meat");
        bird b = new bird("Parrot", 3, "kukekuki kukekuki", "seeds");
        System.out.println("Name: " + m.GetName());
        System.out.println("Age: " + m.GetAge());
        System.out.println("Sound: " + m.GetSound());
        System.out.println("Eat: " + m.GetEat() + "\n");

        System.out.println("Name: " + b.GetName());
        System.out.println("Age: " + b.GetAge());
        System.out.println("Sound: " + b.GetSound());
        System.out.println("Eat: " + b.GetEat());

    }
}
