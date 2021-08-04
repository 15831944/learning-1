package demo.spring;

import org.springframework.stereotype.Component;

@Component("verifyAddress")
public class VerifyAddressImpl implements VerifyAddress {
    @Override
    public boolean verifyAddress(Address address) {
        System.out.println("verifyAddress called");
        if (address.getCity() == null) {
            return false;
        }
        return true;
    }
}
