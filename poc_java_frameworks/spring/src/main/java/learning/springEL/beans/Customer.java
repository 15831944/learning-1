package learning.springEL.beans;

public class Customer {
    private String cust_name;
    private String cust_id;
    private boolean second_handed;
    private double prod_price;
    private String prod_name;
    private Address address;

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String getCust_name() {
        return cust_name;
    }

    public void setCust_name(String cust_name) {
        this.cust_name = cust_name;
    }

    public String getCust_id() {
        return cust_id;
    }

    public void setCust_id(String cust_id) {
        this.cust_id = cust_id;
    }

    public boolean isSecond_handed() {
        return second_handed;
    }

    public void setSecond_handed(boolean second_handed) {
        this.second_handed = second_handed;
    }

    public double getProd_price() {
        return prod_price;
    }

    public void setProd_price(double prod_price) {
        this.prod_price = prod_price;
    }

    public String getProd_name() {
        return prod_name;
    }

    public void setProd_name(String prod_name) {
        this.prod_name = prod_name;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "cust_name='" + cust_name + '\'' +
                ", cust_id='" + cust_id + '\'' +
                ", second_handed=" + second_handed +
                ", prod_price=" + prod_price +
                ", prod_name='" + prod_name + '\'' +
                ",on address " + address +
                '}';
    }
}
