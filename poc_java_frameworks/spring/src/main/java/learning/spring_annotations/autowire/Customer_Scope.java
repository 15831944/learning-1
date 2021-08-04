package learning.spring_annotations.autowire;

import learning.spring_annotations.beans.Address;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope(scopeName = "prototype")
public class Customer_Scope {
    private String customer_name;
    @Autowired
    @Qualifier(value="cust_address")
    private Address cust_address;

    @Autowired(required = false)
    @Qualifier(value = "cust_secAddress")
    private Address cust_secAddress;

    public Address getCust_secAddress() {
        return cust_secAddress;
    }

    public void setCust_secAddress(Address cust_secAddress) {
        this.cust_secAddress = cust_secAddress;
    }

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

    public Customer_Scope() {
        this.customer_name = "John";
        this.cust_address = new Address();
        this.cust_address.setCity_name("Miami");
        this.cust_address.setBuild_no(10);
        this.cust_address.setStreet_name("Florida Keys");
    }
}
