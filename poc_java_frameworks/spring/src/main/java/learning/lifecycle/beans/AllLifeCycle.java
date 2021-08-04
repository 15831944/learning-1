package learning.lifecycle.beans;

import org.springframework.beans.BeansException;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationContextAware;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

public class AllLifeCycle implements InitializingBean, ApplicationContextAware {
    private String message;
    private String name;
    private String id;
    private String serialNumber;
    private String location;
    private ApplicationContext context;

    public AllLifeCycle() {
        System.out.println("Called constructor !");
        message = "Constructed by constructor";
        name = "AllLifeCycle";
    }

    public void init() {
        System.out.println("init get called");
        id = name.toUpperCase();
    }

    public void destroy() {
        name = null;
        System.out.println("Destroy called");
    }

    @Override
    public String toString() {
        return name + " has message " + message + " in location " + location + " with id " + id + " and serialNr=" + serialNumber;
    }
    @Override
    public void afterPropertiesSet() throws Exception {
        name = "Mr." + name;
        System.out.println("After propertiesSet get called");
    }

    public void setSerialNumber(String value) {
        this.serialNumber = value;
    }

    public void setLocation(String value) {
        this.location = value;
    }

    @PostConstruct
    public void init_Second() {
        System.out.println("Initializing in postconstruct!");
    }

    @PreDestroy
    public void destroy_second() {
        System.out.println("Destroying the element in predestroy");
    }

    @Override
    public void setApplicationContext(ApplicationContext applicationContext) throws BeansException {
        this.context = applicationContext;
        System.out.println("context set");
    }
    public void display() {
        context.getBean("AllLifeCycleInitializing");
    }
}
