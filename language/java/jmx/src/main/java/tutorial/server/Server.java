package tutorial.server;

import javax.management.MBeanServer;
import javax.management.ObjectName;
import javax.management.remote.JMXConnectorServer;
import javax.management.remote.JMXConnectorServerFactory;
import javax.management.remote.JMXServiceURL;
import java.io.IOException;
import java.lang.management.ManagementFactory;
import java.rmi.registry.LocateRegistry;
import java.util.Scanner;

public class Server {
    public static void main(String...args) {

        JMXConnectorServer svr = null;
        try {
            LocateRegistry.createRegistry(9999);
            MBeanServer mbs = ManagementFactory.getPlatformMBeanServer();
            JMXServiceURL url = new JMXServiceURL("service:jmx:rmi://localhost:10000/jndi/rmi://localhost:9999/jmxrmi");
            svr = JMXConnectorServerFactory.newJMXConnectorServer(url, null, mbs);
            svr.start();
            ObjectName objectName = new ObjectName("tutorial.server:type=basic,name=game");
            MBeanServer server = ManagementFactory.getPlatformMBeanServer();
            server.registerMBean(new Game(), objectName);
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("To stop server press s");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("s")) {
            System.out.println("Press s to stop not " + str);
            in.nextLine();
        }
        if (svr != null) {
            try {
                svr.stop();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
