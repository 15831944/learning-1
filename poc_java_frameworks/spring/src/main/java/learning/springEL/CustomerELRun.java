package learning.springEL;

import learning.springEL.beans.Customer;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CustomerELRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("springEL_customer.xml");
        Customer customer = (Customer)context.getBean("cust_new1");
        System.out.println(customer);
        customer = (Customer)context.getBean("cust_withRef");
        System.out.println(customer);
        customer = (Customer)context.getBean("cust_withRef_1");
        System.out.println(customer);
        customer = (Customer)context.getBean("cust_calculation");
        System.out.println(customer);
    }
}
