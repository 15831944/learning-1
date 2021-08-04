package learning.lifecycle;

import learning.lifecycle.beans.Car;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CarDependencyInjectionNamespaceRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("dependency_injection.xml");
        Car car = (Car)context.getBean("car_namespaces");
        car.show();
    }
}
