package learning.autowiring;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AutoWiringRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("autowiring.xml");
        AccountService service = (AccountService)context.getBean("accountService");
        service.processUserService();
        HRService hrService = (HRService)context.getBean("hrService");
        hrService.initiateCommunication();
        ExamService exam = (ExamService)context.getBean("examService");
        exam.getExamDetails();
    }
}
