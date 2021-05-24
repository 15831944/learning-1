package patterns.creational.singleton;

/**
 * this is singleton with static initialization.
 */
public class StaffRegisterStatic {
    private static final StaffRegisterStatic instance;
    static {
        instance = new StaffRegisterStatic();
        //perform additional steps
    }
    private StaffRegisterStatic() { }

    public static StaffRegisterStatic getInstance() {
        return instance;
    }

    //Data access methods
}
