package learning.di_annotation.fullJava;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component("professor")
public class Professor {
    private String name;
    public Professor() {
        System.out.println("Object for Professor is created");
    }
    public String getName() {
        return this.name;
    }
    @Autowired
    public void setName(@Value("John")String name) {
        this.name=name;
    }
}
