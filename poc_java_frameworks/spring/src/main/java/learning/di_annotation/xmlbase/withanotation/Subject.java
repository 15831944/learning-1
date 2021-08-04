package learning.di_annotation.xmlbase.withanotation;

import learning.di_annotation.xmlbase.Professor;
import org.springframework.beans.factory.annotation.Autowired;

public class Subject {
    private Professor professor;
    public Subject() {
        System.out.println(" Object for Subject is created");
    }
    @Autowired
    public void setProfessor(Professor professor) {
        System.out.println("setting the professor through setter method injection with autowired annotation");
        this.professor = professor;
    }
    public void taughtBy() {
        if(professor != null) {
            System.out.println("This subject with annothation is taught by " + professor.getName());
        }
    }
}
