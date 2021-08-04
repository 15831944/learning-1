package tutorial;
import org.codehaus.plexus.DefaultPlexusContainer;
import org.codehaus.plexus.PlexusContainer;

import java.net.URL;


public class App {
    public static void main(String...args) throws Exception{
        URL url = App.class.getResource("components.xml");
        System.out.println(url);
        PlexusContainer container = new DefaultPlexusContainer();
        Cheese cheese = (Cheese) container.lookup( Cheese.ROLE, "parmesan" );
        System.out.println( "Parmesan is " + cheese.getAroma() );
        container.dispose();
    }
}
