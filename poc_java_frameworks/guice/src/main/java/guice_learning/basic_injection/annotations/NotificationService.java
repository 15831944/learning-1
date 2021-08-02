package guice_learning.basic_injection.annotations;

//import com.google.inject.ImplementedBy;
import com.google.inject.ProvidedBy;

@ProvidedBy(SMSProvider.class)
//similar but without factory just the implementation of the class ... too static
//@ImplementedBy(SMSService.class)
public interface NotificationService {
	boolean sendNotification(String message, String recipient);

}
