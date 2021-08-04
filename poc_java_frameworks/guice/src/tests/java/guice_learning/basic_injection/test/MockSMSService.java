package guice_learning.basic_injection.test;

import guice_learning.basic_injection.NotificationService;

public class MockSMSService implements NotificationService {

    @Override
    public boolean sendNotification(String message, String recipient) {
        System.out.println("In Test Service :: " + message + " Recipient ::" + recipient);
        return true;
    }
}
