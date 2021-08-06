package application.server;

import application.api.IApplication;
import application.common.CustomClassLoader;
import com.fasterxml.jackson.jaxrs.json.JacksonJaxbJsonProvider;
import org.apache.cxf.jaxrs.JAXRSServerFactoryBean;
import org.apache.cxf.jaxrs.openapi.OpenApiFeature;
import org.apache.cxf.jaxrs.swagger.ui.SwaggerUiConfig;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class Server implements IApplication {

    private OpenApiFeature feature;
    private JAXRSServerFactoryBean restServer;
    private CustomClassLoader customClassLoader;

    public Server(CustomClassLoader customClassLoader) {
        this.customClassLoader = customClassLoader;
        Thread.currentThread().setContextClassLoader(customClassLoader);
    }

    @Override
    public void start() {
        Thread.currentThread().setContextClassLoader(customClassLoader);
        restServer = new JAXRSServerFactoryBean();
        feature = new OpenApiFeature();
        feature.setSwaggerUiConfig(
                new SwaggerUiConfig()
                        .url("/openapi.json"));
        restServer.setProvider(new JacksonJaxbJsonProvider());
   //     restServer.setServiceBean(restController);
        restServer.getFeatures().add(feature);
        restServer.setProvider(new AuthenticationHandler());
        String hostname = "localhost";
        try {
            hostname = InetAddress.getLocalHost().getCanonicalHostName();
        } catch (UnknownHostException e) {
        }
        restServer.setAddress("http://" + hostname + ":" + 8080);
        restServer.create();
    }
    @Override
    public void reconfigure() {

    }

    @Override
    public void stop() {

    }
}
