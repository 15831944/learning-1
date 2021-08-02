package certification.design.interfaces.polymorphism;

public class Oceanographer {
    public void checkSound(LiveInOcean animal) {
        animal.makeSound();
    }
    public static void main(String...args) {
        Oceanographer o = new Oceanographer();
        o.checkSound(new Dolphin());
        o.checkSound(new Whale());
    }
}
