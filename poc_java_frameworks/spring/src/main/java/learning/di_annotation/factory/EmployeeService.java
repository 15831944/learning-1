package learning.di_annotation.factory;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

@Component
public class EmployeeService {
    @Bean("developerBean")
    public Employee getEmployee(@Value("developer")String type) {
        Employee employee = null;
        if("developer".equalsIgnoreCase(type)) {
            employee = new Developer(type);
        } else if ("manager".equalsIgnoreCase(type)) {
            employee = new Manager(type);
        }
        System.out.println("Employee of type " + type + " is created!");
        return employee;
    }
}
