package patterns.creational.builder.dzone;

public class BankAccount {
    public static class Builder {
        private long accountNumber; //this is important so we'll pass it to the constructor
        private String owner;
        private String branch;
        private double balance;
        private double interestRate;

        public Builder(long accountNumber) {
            this.accountNumber = accountNumber;
        }

        public Builder withOwner(String owner) {
            this.owner = owner;
            return this;
        }

        public Builder atBranch(String branch) {
            this.branch = branch;
            return this;
        }

        public Builder openingBalance(double balance) {
            this.balance = balance;
            return this;
        }

        public Builder atRate(double interestRate) {
            this.interestRate = interestRate;
            return this;
        }

        public BankAccount build() {
            //Here we create the actual account object, which is always in a fully initialized state
            BankAccount account = new BankAccount();
            account.accountNumber = this.accountNumber;
            account.owner = this.owner;
            account.balance = this.balance;
            account.branch = this.branch;
            account.interestRate = this.interestRate;
            return account;
        }
    }

    private long accountNumber;
    private String owner;
    private double balance;
    private String branch;
    private double interestRate;

    private BankAccount() {
    }

    public long getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(long accountNumber) {
        this.accountNumber = accountNumber;
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

    public String getBranch() {
        return branch;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }
}
