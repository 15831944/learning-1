package application.routes;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;

@Path("/cxf_classworlds/advanced")
public class DefaultAdvancedRoute {
    @Path("/info")
    @GET
    @Produces("application/text")
    public String getInfo() {
        return "server is alive from second advanced route";
    }
}
