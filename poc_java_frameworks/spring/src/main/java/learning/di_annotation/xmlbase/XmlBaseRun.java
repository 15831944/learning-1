package learning.di_annotation.xmlbase;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class XmlBaseRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("di_annotation_xmlbase.xml");
        Subject subject = (Subject)context.getBean("subject");
        subject.taughtBy();
        System.out.println("with annotation");System.out.flush();
        learning.di_annotation.xmlbase.withanotation.Subject subjectAuto = (learning.di_annotation.xmlbase.withanotation.Subject)context.getBean("subjectAuto");
        subjectAuto.taughtBy();
    }
}
