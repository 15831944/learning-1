package learning.spring_annotations;

import learning.spring_annotations.stereotype.Customer_Component;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class StereotypeRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring_annotations_stereotype.xml");
        Customer_Component customer = (Customer_Component)context.getBean("customer_Component");
        System.out.println(customer.getCustomer_name() + " at " + customer.getCust_address());
    }
}
