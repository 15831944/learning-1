package learning.di_annotation.beans;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class Professor {
    @Value(value="John")
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
