package guice_learning.basic_injection.constructor;

import com.google.inject.Guice;
import com.google.inject.Injector;
import guice_learning.basic_injection.constructor.ApplicationModule;

public class NotificationClient {

	public NotificationClient() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String...args) {
		Injector injector = Guice.createInjector(new ApplicationModule());
		AppConsumer app = injector.getInstance(AppConsumer.class);
		app.sendNotification("Hello", "9896666");
	}

}
