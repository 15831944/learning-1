package guice_learning.basic_injection;

import com.google.inject.AbstractModule;
import com.google.inject.name.Names;

public class ApplicationModuleMultiple extends AbstractModule {
    @Override
    public void configure() {
        bind(NotificationService.class).annotatedWith(Names.named("sms")).to(SMSService.class);
        bind(NotificationService.class).annotatedWith(Names.named("email")).to(EmailService.class);
    }
}
