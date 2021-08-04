package learning.autowiring;

public class ExamService {
    private StudentService studentService;
    private String examServiceType;

    public ExamService(StudentService studentService, String examServiceType) {
        this.examServiceType=examServiceType;
        this.studentService = studentService;
    }
    public void getExamDetails() {
        if(studentService != null) {
            System.out.println("Exam Service Type = " + examServiceType);
            studentService.getStudentDetail();
        }
    }
}
