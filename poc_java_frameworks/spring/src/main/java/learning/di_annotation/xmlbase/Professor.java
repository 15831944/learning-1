package learning.di_annotation.xmlbase;

public class Professor {
    private String name;
    public Professor() {
        System.out.println("Object for Professor is created.");
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        System.out.println("Set name for the professor:" + name);
        this.name = name;
    }
}
