package aop;

import aop.service.EmployeeService;
import aop.service.HRService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringAOPInXMLCheck {

    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("aop_application_context.xml");
        EmployeeService employeeService = (EmployeeService)context.getBean("employeeService");
        employeeService.generateSalarySlip();
        employeeService.showTotalEmployee("test");
        employeeService.findEmployee("abc123");

        HRService hrService = (HRService)context.getBean("hrService");
        hrService.showHolidayList();
        hrService.showHolidayListWithData();
        try {
            hrService.showMyLeave();
        } catch (Exception e) {
            System.out.println("Exception catched as expected.");
        }
    }
}
