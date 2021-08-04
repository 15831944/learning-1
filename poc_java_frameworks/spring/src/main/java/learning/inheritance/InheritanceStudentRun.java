package learning.inheritance;

import learning.inheritance.beans.EnggStudent;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class InheritanceStudentRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("inheritance.xml");
        EnggStudent engStudent = (EnggStudent)context.getBean("EnggStudent");
        System.out.println(engStudent);
        engStudent = (EnggStudent)context.getBean("EnggStudentParent");
        System.out.println(engStudent);
    }
}
