package guice_learning.basic_injection.annotations;

import com.google.inject.*;


public class NotificationClient {
    public static void main(String...args) {
        Injector injector = Guice.createInjector(new AbstractModule() {
            @Override
            protected void configure() {
                super.configure();
            }
        });
        NotificationService service = injector.getInstance(NotificationService.class);
        service.sendNotification("Send","data");
    }
}
