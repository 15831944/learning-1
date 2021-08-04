package guice_learning.basic_injection.constructor;


import com.google.inject.Inject;
import guice_learning.basic_injection.NotificationService;

public class AppConsumer {

	private NotificationService notificationService;
	public AppConsumer() {
		// TODO Auto-generated constructor stub
	}

	@Inject
	public void setService(NotificationService service) {
		this.notificationService = service;
	}
	
	public boolean sendNotification(String message, String recipient) {
		return notificationService.sendNotification(message, recipient);
	}
}
