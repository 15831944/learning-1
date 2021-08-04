package guice_learning.basic_injection.annotations;

import com.google.inject.Provider;

public class SMSProvider implements Provider<NotificationService> {
    @Override
    public NotificationService get() {
        return new SMSService();
    }
}
