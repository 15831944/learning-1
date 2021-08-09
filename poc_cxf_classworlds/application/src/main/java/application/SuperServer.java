package application;

import application.api.IApplication;
import application.common.CustomClassLoader;
import org.codehaus.plexus.classworlds.ClassWorld;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;

import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;
import java.util.Scanner;

public class SuperServer {

    private ClassWorld world;

    private IApplication application;

    public SuperServer(ClassWorld world) {
        this.world = world;
    }
    public static void main(String[] args, ClassWorld world) {
        SuperServer superServer = new SuperServer(world);
        superServer.start();
    }
    public void start() {
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        ClassRealm realm = null;
        try {
            realm = world.getRealm("cxf");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        ClassRealm realmApplication = null;
        try {
            realmApplication = world.getRealm("application");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        realm.setParentClassLoader(realmApplication);
        CustomClassLoader classLoader = new CustomClassLoader(orig);
        classLoader.addClassLoader(realm);
        classLoader.addClassLoader(orig);
        classLoader.addClassLoader(realmApplication);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> applicationClass = classLoader.loadClass("application.server.RestServer");
            if (applicationClass == null) {
                Arrays.stream(realm.getURLs()).forEach(System.out::println);
                System.out.println("Could not load RestServer");
                System.exit(-1);
            }
            application = (IApplication) applicationClass
                    .getDeclaredConstructor(CustomClassLoader.class)
                    .newInstance(classLoader);
            application.start();
        } catch (ClassNotFoundException | NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
            Thread.currentThread().setContextClassLoader(orig);
            return;
        }
        System.out.println("Replace the route");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("r")) {
            in.nextLine();
        }
        application.reconfigure();
        System.out.println("Press s to stop");
        in = new Scanner(System.in);
        str = in.nextLine();
        while(!str.equals("s")) {
            in.nextLine();
        }
        application.stop();
    }
}
