package patterns.creational.builder.dzone;

public class BankAccountv2 {
    private long acccountNumber;
    private String owner;
    private double balance;
    private String branch;
    private double interestRate;

    public BankAccountv2(long acccountNumber, String owner, String branch, double balance, double interestRate) {
        this.acccountNumber = acccountNumber;
        this.owner = owner;
        this.balance = balance;
        this.branch = branch;
        this.interestRate = interestRate;
    }

    public long getAcccountNumber() {
        return acccountNumber;
    }

    public void setAcccountNumber(long acccountNumber) {
        this.acccountNumber = acccountNumber;
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public String getBranch() {
        return branch;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }
}
