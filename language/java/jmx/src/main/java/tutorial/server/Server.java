package tutorial.server;

import javax.management.*;
import java.lang.management.ManagementFactory;
import java.util.Scanner;

public class Server {
    public static void main(String...args) {
        try {
            ObjectName objectName = new ObjectName("tutorial.server:type=basic,name=game");
            MBeanServer server = ManagementFactory.getPlatformMBeanServer();
            server.registerMBean(new Game(), objectName);
        } catch (MalformedObjectNameException | InstanceAlreadyExistsException | MBeanRegistrationException | NotCompliantMBeanException e) {
            e.printStackTrace();
        }
        System.out.println("To stop server press s");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("s")) {
            in.nextLine();
        }
    }
}
