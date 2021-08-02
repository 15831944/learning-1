package learning.setter_injection;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SetterInjectionRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("SetterInjection.xml");
        DocumentBase doc = (DocumentBase)context.getBean("documentBase");
        doc.performSearch();
    }
}
