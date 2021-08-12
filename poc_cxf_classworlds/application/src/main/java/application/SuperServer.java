package application;

import application.api.IApplication;
import application.launcher.RESTApplication;
import org.codehaus.plexus.classworlds.ClassWorld;

import javax.management.*;
import java.lang.management.ManagementFactory;
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
        MBeanServer server = ManagementFactory.getPlatformMBeanServer();
        application = new RESTApplication(world, server);
/*  this has been moved to jmx connection
        application.start();
        System.out.println("Replace the route and then press r");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("r")) {
            in.nextLine();
        }
        application.reconfigure(); */
        System.out.println("Press s to stop");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("s")) {
            in.nextLine();
        }
        application.stop();
    }
}
