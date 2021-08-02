package demo.spring;

import org.springframework.stereotype.Component;

@Component("verifyCredit")
public class VerifyCreditImpl implements VerifyCredit {
    @Override
    public String verifyCredit(Customer customer) {
        System.out.println("verifyCredit called with SSN " + customer.getSSN());
        if (customer.getSSN().startsWith("A")) {
            return GOOD_CREDIT;
        } else {
            return BAD_CREDIT;
        }
    }
}
