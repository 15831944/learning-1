package learning.di_annotation.xmlbase;

public class Subject {
    private Professor professor;
    public Subject() {
        System.out.println(" Object for Subject is created");
    }
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
