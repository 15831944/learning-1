package learning.lifecycle;

import learning.lifecycle.beans.AllLifeCycle;
import learning.lifecycle.beans.AllLifeCycleInitializing;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AllLifeCyleRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("beans_lifecycle.xml");
        AllLifeCycle obj = (AllLifeCycle) context.getBean("AllLifeCycle");
        System.out.println(obj);
        obj.display();
        AllLifeCycleInitializing init = (AllLifeCycleInitializing)context.getBean("AllLifeCycleInitializing");
        System.out.println(init);
        ((AbstractApplicationContext)context).registerShutdownHook();
        System.out.println("Static Factory");
        AllLifeCycleFactory factory = (AllLifeCycleFactory) context.getBean("AllLifeCycleFactory");
        factory.buildObject().display();
        ((AbstractApplicationContext)context).registerShutdownHook();
    }
}
