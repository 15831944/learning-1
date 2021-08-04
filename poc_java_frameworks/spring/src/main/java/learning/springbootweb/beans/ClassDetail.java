package learning.springbootweb.beans;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Repository;

@Repository
@Scope(value = "session", proxyMode = ScopedProxyMode.TARGET_CLASS)
public class ClassDetail implements  SessionBeanScope {
    @Autowired
    SessionBeanScope sessionBeanScope;
    @Autowired
    PrototypeBeanScope prototypeBeanScope;

    private static int increment = 0;

    public ClassDetail() {
        System.out.println(" \n ::::::: Object of ClassDetail bean with session scope created " + (++increment)
                + " Times ::::::: ");
    }

    public void printClassDetail() {
        System.out.println("\n ::::::::: Session Bean - PrintMessage Method Called ::::::::::::::::::: ");
        System.out.println("\n ::::::::: SessionBeanScope :: printClassDetail() Called ::::::::::::::: ");
    }
}
