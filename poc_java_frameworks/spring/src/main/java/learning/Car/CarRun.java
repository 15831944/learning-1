package learning.Car;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CarRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("first_car.xml");
        Car theCar = (Car)context.getBean("firstCar");
        theCar.showType();
    }
}
