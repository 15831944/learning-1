package guice_learning.basic_injection.annotations.named;

import com.google.inject.AbstractModule;
import com.google.inject.Guice;
import com.google.inject.Injector;
import com.google.inject.name.Names;


public class NotificationClient {
    public static void main(String...args) {
        Injector injector = Guice.createInjector(new AbstractModule() {
            @Override
            protected void configure() {
                bind(NotificationService.class).annotatedWith(Names.named("SMS")).to(SMSService.class);
            }
        });
        AppConsumer service = injector.getInstance(AppConsumer.class);
        service.sendNotification("Send","data");
    }
}
