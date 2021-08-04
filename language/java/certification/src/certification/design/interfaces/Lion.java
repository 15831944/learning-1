package certification.design.interfaces;

public class Lion implements Run{
    @Override
    public boolean isQuadruped() {
        return true;
    }

    public boolean canHuntWhileRunning() {
        return true;
    }

    public double getMaxSpeed() {
        return 100;
    }
    public static void main(String...args) {
        Run run = new Lion();
        System.out.println("Lion can hunt while running ? " + run.canHuntWhileRunning());
        System.out.println("Lion max speed is " + run.getMaxSpeed());
    }
}
