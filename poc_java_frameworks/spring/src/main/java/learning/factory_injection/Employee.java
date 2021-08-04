package learning.factory_injection;

public class Employee {
    private String type;
    public Employee(String type) {
        this.type = type;
    }
    public void showType() {
        System.out.println("Type is:" + type);
    }
}
