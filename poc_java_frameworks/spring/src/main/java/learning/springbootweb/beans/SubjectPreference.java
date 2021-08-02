package learning.springbootweb.beans;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope("prototype")
public class SubjectPreference implements  PrototypeBeanScope{

    private static int increment = 0;

    public SubjectPreference() {
        super();
        System.out.println("\n ::: Object of StudentPreference bean is created " +(++increment) + " times ::::");
    }
}
