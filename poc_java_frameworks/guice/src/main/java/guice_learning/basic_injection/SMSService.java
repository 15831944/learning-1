package guice_learning.basic_injection;


import com.google.inject.Singleton;

@Singleton
public class SMSService implements NotificationService{

	@Override
	public boolean sendNotification(String message, String recipient) {
		System.out.println("SMS has been sent to  " + recipient + " with message=" + message);
		return true;
	}

}
