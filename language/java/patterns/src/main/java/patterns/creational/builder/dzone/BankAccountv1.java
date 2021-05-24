package patterns.creational.builder.dzone;

public class BankAccountv1 {
    private long acccountNumber;
    private String owner;
    private double balance;

    public BankAccountv1(long acccountNumber, String owner, double balance) {
        this.acccountNumber = acccountNumber;
        this.owner = owner;
        this.balance = balance;
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

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
}
