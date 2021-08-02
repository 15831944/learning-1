package guice_learning.basic_injection.constructor;


import com.google.inject.Singleton;
import guice_learning.basic_injection.NotificationService;

@Singleton
public class SMSService implements NotificationService{

	private SMSDatabaseConnection databaseConnection = null;
	public SMSService(SMSDatabaseConnection connection) {
		this.databaseConnection = connection;
	}
	@Override
	public boolean sendNotification(String message, String recipient) {
		System.out.println("SMS has been sent to  " + recipient + " with message=" + message + " on connection " + databaseConnection.getName());
		return true;
	}

}
