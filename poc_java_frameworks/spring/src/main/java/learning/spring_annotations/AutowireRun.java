package learning.spring_annotations;

import learning.spring_annotations.autowire.Customer_Autowire;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AutowireRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring_annotations_autowire.xml");
        Customer_Autowire customer = (Customer_Autowire)context.getBean("customer_Autowire");
        System.out.println(customer.getCustomer_name() + " at " + customer.getCust_address() + " second address = " + customer.getCust_secAddress() );
    }
}
