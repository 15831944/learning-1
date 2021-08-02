package learning.di_annotation.factory;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class DIFactoryRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("di_annotation_factory.xml");
        SalaryService salaryService = (SalaryService)context.getBean("salaryService");
        salaryService.showEmployeeType();
    }
}
