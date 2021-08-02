package demo.spring;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import java.util.Date;

public class LoanProcessClient {
    public static void main(String... args) {
        ApplicationContext appContext = new AnnotationConfigApplicationContext(JavaBaseConfig.class);
        Customer customer = new Customer();
        customer.setFirstname("Naveen");
        customer.setLastname("Balani");
        customer.setSSN("A0989999999");
        //Address
        Address address = new Address();
        address.setAddressLine1("Stree one");
        address.setCity("Mumbai");
        address.setCountry("India");
        customer.setAddress(address);
        Loan loan = new Loan();
        loan.setCustomer(customer);
        loan.setLoanApplyDate(new Date());
        LoanProcess loanProcess = (LoanProcess) appContext.getBean("loanProcess");
        Loan loanResponse =loanProcess.applyLoan(loan);
    }
}
