package learning.jsr_annotations;

import learning.jsr_annotations.beans.Customer;
import learning.jsr_annotations.config.MyConfiguration;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class AnnotationConfigurationRun {
    public static void main(String...args) {
        ApplicationContext context = new AnnotationConfigApplicationContext(MyConfiguration.class);
        Customer customer = (Customer)context.getBean("myCustomer");
        System.out.println(customer.getCust_name() + "\t" + customer.getCust_it());
    }
}
