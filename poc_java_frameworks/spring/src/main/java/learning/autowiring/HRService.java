package learning.autowiring;

public class HRService {
    private EmailService emailService = null;
    public void setEmailService(EmailService emailService) {
        this.emailService = emailService;
    }
    public void initiateCommunication() {
        if(emailService!=null) {
            emailService.sendEmail();
        }
    }
}
