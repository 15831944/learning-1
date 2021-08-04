package learning.di_annotation.beans.qualified;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
public class Subject {
    private Professor professor;
    public Subject() {
        System.out.println(" Object for Subject is created");
    }
    @Autowired
    @Qualifier("professor_1")
    public void setProfessor(Professor professor) {
        System.out.println("setting the professor through setter method injection");
        this.professor = professor;
    }
    public void taughtBy() {
        if(professor != null) {
            System.out.println("This subject is taught by " + professor.getName());
        }
    }
}
