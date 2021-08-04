package learning.springbootweb.beans;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Service;

@Service
@Scope("singleton")
public class StudentDetail implements SingletonBeanScope {
    @Autowired
    PrototypeBeanScope prototypeBeanScope;

    private static int increment = 0;
    public StudentDetail() {
        super();
        System.out.println("\n ::: Object of StudentDetail bean is created " +(++increment) + " times ::::");
    }
}
