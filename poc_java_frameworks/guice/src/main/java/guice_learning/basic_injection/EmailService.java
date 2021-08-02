package guice_learning.basic_injection;

public class EmailService implements NotificationService {
    @Override
    public boolean sendNotification(String message, String recipient) {
        System.out.println("Send Email notification at recipient : " + recipient + " with message : " + message);
        return true;
    }
}
