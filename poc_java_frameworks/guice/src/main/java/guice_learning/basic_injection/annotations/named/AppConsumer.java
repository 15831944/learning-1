package guice_learning.basic_injection.annotations.named;


import com.google.inject.Inject;
import com.google.inject.name.Named;

public class AppConsumer {

	private NotificationService notificationService;
	public AppConsumer() {
		// TODO Auto-generated constructor stub
	}

	@Inject
	public void setService(@Named("SMS") NotificationService service) {
		this.notificationService = service;
	}
	
	public boolean sendNotification(String message, String recipient) {
		return notificationService.sendNotification(message, recipient);
	}
}
