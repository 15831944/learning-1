package learning.constructor_injection;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class ConstructorInjectionRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("ConstructorInjection.xml");
        EmployeeService employeeService = (EmployeeService)context.getBean("employeeConstructor");
        employeeService.showEmployeeName();
        Camera camera = (Camera)context.getBean("cameraConstructor");
        camera.showSettings();
        camera = (Camera) context.getBean("cameraConstructorFlash");
        camera.showSettings();
    }
}
