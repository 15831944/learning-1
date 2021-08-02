package guice_learning.basic_injection;

public class SMSDatabase  extends SMSService{
    @Override
    public boolean sendNotification(String message, String recipient) {
        System.out.println("Send SMS Database to recipient: " + recipient + " with message : " + message);
        return true;
    }
}
