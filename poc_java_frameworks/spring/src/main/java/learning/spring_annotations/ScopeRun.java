package learning.spring_annotations;

import learning.spring_annotations.autowire.Customer_Autowire;
import learning.spring_annotations.autowire.Customer_Scope;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class ScopeRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring_annotations_autowire.xml");
        Customer_Autowire customer1 = (Customer_Autowire)context.getBean("customer_Autowire");
        Customer_Autowire customer2 = (Customer_Autowire)context.getBean("customer_Autowire");
        System.out.println(customer2.getCustomer_name() + " at " + customer2.getCust_address() + " second address = " + customer2.getCust_secAddress() );
        System.out.println(customer1.getCustomer_name() + " at " + customer1.getCust_address() + " second address = " + customer1.getCust_secAddress() );
        System.out.println("Changed customer1 to Smith");
        customer1.setCustomer_name("Smith");
        System.out.println(customer2.getCustomer_name() + " at " + customer2.getCust_address() + " second address = " + customer2.getCust_secAddress() );
        System.out.println(customer1.getCustomer_name() + " at " + customer1.getCust_address() + " second address = " + customer1.getCust_secAddress() );
        System.out.println("Scope customer autowired");
        Customer_Scope customerS1 = (Customer_Scope)context.getBean("customer_Scope");
        Customer_Scope customerS2 = (Customer_Scope)context.getBean("customer_Scope");
        System.out.println(customerS1.getCustomer_name() + " at " + customerS1.getCust_address() + " second address = " + customerS1.getCust_secAddress() );
        System.out.println(customerS2.getCustomer_name() + " at " + customerS2.getCust_address() + " second address = " + customerS2.getCust_secAddress() );
        System.out.println("Changed customerS1 to Smith");
        customerS1.setCustomer_name("Smith");
        System.out.println(customerS1.getCustomer_name() + " at " + customerS1.getCust_address() + " second address = " + customerS1.getCust_secAddress() );
        System.out.println(customerS2.getCustomer_name() + " at " + customerS2.getCust_address() + " second address = " + customerS2.getCust_secAddress() );
    }
}
