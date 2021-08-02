package guice_learning.serviceprovider;

public class ServiceConnection {
    public void startService() {
        System.out.println("Start SMS Notification service");
    }

    public void stopService() {
        System.out.println("Stop SMS Notification service");
    }
}
