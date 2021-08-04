package guice_learning.basic_injection;

import com.google.inject.AbstractModule;
import com.google.inject.Guice;
import com.google.inject.Injector;
import com.google.inject.name.Named;

public class NotificationClient {

	public NotificationClient() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String...args) {
		Injector injector = Guice.createInjector(new ApplicationModule());
		AppConsumer app = injector.getInstance(AppConsumer.class);
		app.sendNotification("Hello", "9896666");

		//linked binding
		injector = Guice.createInjector(new AbstractModule() {
			@Override
			protected void configure() {
				bind(NotificationService.class).to(SMSService.class);
				bind(SMSService.class).to(SMSDatabase.class);
			}
		});
		app = injector.getInstance(AppConsumer.class);
		app.sendNotification("Hello", "9896666");
		//instance binding
		injector = Guice.createInjector(new AbstractModule() {
			@Override
			protected void configure() {
				bind(NotificationService.class).toInstance(new SMSDatabase());
			}
		});
		app = injector.getInstance(AppConsumer.class);
		app.sendNotification("Hello", "9896666");
/* this doesn't work ...
		injector = Guice.createInjector(new ApplicationModuleMultiple());
		app = injector.getInstance(@Named("sms") AppConsumer.class);
		app.sendNotification("Hello", "9666");
		app = injector.getInstance(@Named("email") AppConsumer.class);
		app.sendNotification("Hello", "9666");
 */
	}

}
