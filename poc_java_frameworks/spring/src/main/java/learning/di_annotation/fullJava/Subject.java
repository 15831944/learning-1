package learning.di_annotation.fullJava;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component("subjectBean")
public class Subject {
    private Professor professor;
    public Subject() {
        System.out.println("Object of Subject is created!");
    }
    @Autowired
    public void setProfessor(Professor professor) {
        System.out.println("setting the professor through setter method injection ");
        this.professor = professor;
    }
    public void taughBy() {
        if(professor != null) {
            System.out.println("This subject is taught by " + professor.getName());
        }
    }
}
