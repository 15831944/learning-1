package certification.design.interfaces;

public interface Run extends  Walk {
    public abstract boolean canHuntWhileRunning();
    abstract double getMaxSpeed();
}
