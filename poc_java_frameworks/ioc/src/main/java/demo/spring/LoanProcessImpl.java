package demo.spring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component("loanProcess")
public class LoanProcessImpl implements LoanProcess {

    @Autowired
    private VerifyAddress verifyAddress;
    @Autowired
    private VerifyCredit verifyCredit;
    @Autowired
    private LoanAssessment loanAssessment;

    @Override
    public Loan applyLoan(Loan loan) {
        //Step one - verify address
        boolean validAddress = getVerifyAddress().verifyAddress(loan.getCustomer().getAddress());
        if (!validAddress) {
            throw new RuntimeException("Address for Customer SSN " + loan.getCustomer().getSSN() + " is not valid");
        }
        //Step two -verify credit
        String status = getVerifyCredit().verifyCredit(loan.getCustomer());
        if (status.equalsIgnoreCase(VerifyCredit.BAD_CREDIT)) {
            //If bad credit, disapprove Loan
            loan.setLoanStatus(LoanAssessment.LOAN_REJECTED);
            return loan;
        } else {
            return getLoanAssessment().assessLoan(loan);
        }
    }

    @Override
    public VerifyAddress getVerifyAddress() {
        return verifyAddress;
    }

    @Override
    public void setVerifyAddress(VerifyAddress verifyAddress) {
        this.verifyAddress = verifyAddress;
    }

    @Override
    public VerifyCredit getVerifyCredit() {
        return verifyCredit;
    }

    @Override
    public void setVerifyCredit(VerifyCredit verifyCredit) {
        this.verifyCredit = verifyCredit;
    }

    @Override
    public LoanAssessment getLoanAssessment() {
        return loanAssessment;
    }

    @Override
    public void setLoanAssessment(LoanAssessment loanAssessment) {
        this.loanAssessment = loanAssessment;
    }
}
