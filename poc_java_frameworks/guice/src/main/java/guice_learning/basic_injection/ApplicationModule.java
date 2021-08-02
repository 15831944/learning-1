package guice_learning.basic_injection;

import com.google.inject.AbstractModule;

public class ApplicationModule extends AbstractModule {

	public ApplicationModule() {
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void configure() {
		//bind service to the implementation class
		//if we implements Module then the bind should be binder.bind
		bind(NotificationService.class).to(SMSService.class);
	}
}
