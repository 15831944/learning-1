package learning.lifecycle;

import learning.lifecycle.beans.AllLifeCycle;

public class AllLifeCycleFactory {
    private static AllLifeCycle lifeCyle = new AllLifeCycle();
    private static AllLifeCycleFactory factory = new AllLifeCycleFactory();

    private AllLifeCycleFactory() {

    }

    public AllLifeCycle buildObject() {
        System.out.println("building object");
        return lifeCyle;
    }
    public static AllLifeCycleFactory createFactory() {
        System.out.println("CreateFactory for AllLifeCycleFactory");
        return factory;
    }
}
