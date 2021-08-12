package tutorial.client;

import tutorial.server.api.GameMXBean;

import javax.management.MBeanServerConnection;
import javax.management.ObjectName;
import javax.management.remote.JMXConnector;
import javax.management.remote.JMXConnectorFactory;
import javax.management.remote.JMXServiceURL;
import javax.management.JMX;
import java.util.Arrays;

import static java.lang.Thread.sleep;

public class Client {
    public static void main(String...args) throws Exception {
        echo("\nCreate an RMI connector client and " +
                "connect it to the RMI connector server");
        JMXServiceURL url =
                new JMXServiceURL("service:jmx:rmi:///jndi/rmi://:9999/jmxrmi");
        JMXConnector jmxc = JMXConnectorFactory.connect(url, null);
        MBeanServerConnection mbsc = jmxc.getMBeanServerConnection();
        echo("\nDomains:");
        String domains[] = mbsc.getDomains();
        Arrays.sort(domains);
        for (String domain : domains) {
            echo("\tDomain = " + domain);
        }
        ClientListener listener = new ClientListener();
        ObjectName mbeanName = new ObjectName("tutorial.server:type=basic,name=game");
        GameMXBean mbeanProxy = JMX.newMBeanProxy(mbsc, mbeanName,
                GameMXBean.class, true);

//        echo("\nAdd notification listener...");
//        mbsc.addNotificationListener(mbeanName, listener, null, null);

        echo("\nPlayerName = " + mbeanProxy.getPlayerName());
        mbeanProxy.setPlayerName("Hagi");

        echo("\nWaiting for notification...");
        sleep(2000);
        echo("\nPlayerName = " + mbeanProxy.getPlayerName());
        echo("\nInvoke playFootball in Game MBean...");
        mbeanProxy.playFootball("Romania");
        jmxc.close();
    }
    public static void echo(String message) {
        System.out.println(message);
    }
}
