package learning.spring_annotations.stereotype;

import learning.spring_annotations.beans.Address;
import org.springframework.stereotype.Component;

@Component
public class Customer_Component {
    private String customer_name;
    private Address cust_address;

    public String getCustomer_name() {
        return customer_name;
    }

    public void setCustomer_name(String customer_name) {
        this.customer_name = customer_name;
    }

    public Address getCust_address() {
        return cust_address;
    }

    public void setCust_address(Address cust_address) {
        this.cust_address = cust_address;
    }

    public Customer_Component() {
        this.customer_name = "John";
        this.cust_address = new Address();
        this.cust_address.setCity_name("Miami");
        this.cust_address.setBuild_no(10);
        this.cust_address.setStreet_name("Florida Keys");
    }
}
