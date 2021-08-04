package learning.factory_injection;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class FactoryInjectionRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("factory_injection.xml");
        SearchacleFactory factory = (SearchacleFactory)context.getBean("searchableFactory");
        SalaryService salary = (SalaryService)context.getBean("salaryService");
        salary.showEmployeeType();
    }
}
