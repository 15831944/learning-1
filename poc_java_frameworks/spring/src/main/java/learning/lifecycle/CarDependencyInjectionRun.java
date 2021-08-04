package learning.lifecycle;

import learning.lifecycle.beans.Car;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CarDependencyInjectionRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("dependency_injection.xml");
        Car car = (Car)context.getBean("car_obj");
        car.show();
        System.out.println("constructor injection");
        car = (Car)context.getBean("car_constructor");
        car.show();
        System.out.println("using private");
        car = (Car)context.getBean("car_private_constructor_DI");
        car.show();
    }
}
