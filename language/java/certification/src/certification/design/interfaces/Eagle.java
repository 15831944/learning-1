package certification.design.interfaces;

public class Eagle implements Fly{

    public int getWingSpan() {
        return 15;
    }

    @Override
    public void land() {
        System.out.println("Eagle is diving fast");
    }
    public static void main(String...args) {
        Fly eagle = new Eagle();
        eagle.land();
    }
}
