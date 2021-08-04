package guice_learning.basic_injection.constructor;

import com.google.inject.AbstractModule;
import guice_learning.basic_injection.NotificationService;

public class ApplicationModule extends AbstractModule {
    @Override
    protected void configure() {
        try {
            bind(NotificationService.class).toConstructor(SMSService.class.getConstructor(SMSDatabaseConnection.class));
        } catch (NoSuchMethodException ex) {
            ex.printStackTrace();
        }
    }
}
