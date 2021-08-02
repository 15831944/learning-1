package learning.jsr_annotations.beans;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.inject.Inject;
import javax.inject.Named;

//@Named
@Component
public class Customer {
    private String cust_name;
    private int cust_it;

    //@Inject
    @Autowired
    private Address cust_address;

    public Customer() {
    }

    public Customer(String cust_name, int cust_it) {
        this.cust_name = cust_name;
        this.cust_it = cust_it;
    }

    public String getCust_name() {
        return cust_name;
    }

    public void setCust_name(String cust_name) {
        this.cust_name = cust_name;
    }

    public int getCust_it() {
        return cust_it;
    }

    public void setCust_it(int cust_it) {
        this.cust_it = cust_it;
    }
}
