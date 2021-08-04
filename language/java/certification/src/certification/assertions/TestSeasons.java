package certification.assertions;

public class TestSeasons {
    public static void test(Seasons s) {
        switch (s) {
            case SPRING:
            case FALL:
                System.out.println("Shorter hours");
                break;
            case SUMMER:
                 System.out.println("Longer hours");
                break;
            default:
                assert false: "Invalid season";
        }
    }
    public static void main(String [] args) {
        //test (Seasons.WINTER); //this work only with jars or already compiled classes
    }
}
