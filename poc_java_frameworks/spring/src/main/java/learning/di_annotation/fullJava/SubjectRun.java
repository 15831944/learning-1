package learning.di_annotation.fullJava;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class SubjectRun {
    public static void main(String...args) {
        ApplicationContext context = new AnnotationConfigApplicationContext(JavaBaseSpringConfig.class);
        Subject subject = (Subject)context.getBean("subjectBean");
        subject.taughBy();
    }
}
