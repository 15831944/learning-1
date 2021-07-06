package gdimitriu.poc_karaf.poc_cxf;

import com.fasterxml.jackson.jaxrs.json.JacksonJaxbJsonProvider;
import org.apache.cxf.endpoint.Server;
import org.apache.cxf.jaxrs.JAXRSServerFactoryBean;
//import org.apache.cxf.jaxrs.openapi.OpenApiFeature;
//import org.apache.cxf.jaxrs.swagger.ui.SwaggerUiConfig;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

public class CxfServer {
    private JAXRSServerFactoryBean restServer;
//    private OpenApiFeature feature;
    private Server server;
    private RestController restController = new RestController();
    public void start() {
        restServer = new JAXRSServerFactoryBean();
        restServer.setProvider(new JacksonJaxbJsonProvider());
        restServer.setServiceBean(restController);
//        feature = new OpenApiFeature();
//        feature.setSwaggerUiConfig(
//                new SwaggerUiConfig()
//                        .url("/kafka/client/openapi.json"));
//        restServer.setFeatures(Arrays.asList(feature));
        String hostname = "localhost";
        try {
            hostname = InetAddress.getLocalHost().getCanonicalHostName();
        } catch (UnknownHostException e) {
        }
        restServer.setAddress("http://" + hostname + ":8080");
        server = restServer.create();
    }

    public void stop() {
        server.stop();
        server.destroy();
    }
}
