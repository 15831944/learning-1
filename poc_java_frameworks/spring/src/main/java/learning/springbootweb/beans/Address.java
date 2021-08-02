package learning.springbootweb.beans;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;

@Component
@Scope(value = "request", proxyMode = ScopedProxyMode.TARGET_CLASS)
public class Address implements  RequestBeanScope{

    private static int increment = 0;

    @Autowired
    PrototypeBeanScope prototypeBeanScope;

    public Address() {
        super();
        System.out.println("\n ::: Object of Address bean is created " +(++increment) + " times ::::");
    }
    @Override
    public void printAddress() {
        System.out.println("\n :::::::::::::: RequestbeanScope :: printAddress() Called :::::::::::::: ");
    }
}
