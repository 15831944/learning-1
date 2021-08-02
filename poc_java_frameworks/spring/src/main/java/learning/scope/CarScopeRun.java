package learning.scope;

import learning.scope.beans.Car;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class CarScopeRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("scope.xml");
        System.out.println("Singleton default car");
        Car car1 = (Car) context.getBean("car_singleton_default");
        car1.show();
        Car car2 = (Car)context.getBean("car_singleton_default");
        car2.show();
        car1.setColor("red");
        System.out.println("After setting the color to red to car1");
        car1.show();
        car2.show();
        System.out.println("Prototype car");
        car1 = (Car)context.getBean("car_prototype");
        car2 = (Car) context.getBean("car_prototype");
        car1.show();
        car2.show();
        System.out.println("Changing color to first car");
        car1.setColor("red");
        car1.show();
        car2.show();
    }
}
