package learning.jsr_annotations.config;

import learning.jsr_annotations.beans.Customer;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Component;

@Component
@ComponentScan(basePackages = "learning.jsr_annotations.beans")
public class MyConfiguration {

    @Bean(name="myCustomer")
    public Customer myCustomer() {
        Customer customer = new Customer();
        customer.setCust_name("name by config");
        customer.setCust_it(20);
        return customer;
    }

}
