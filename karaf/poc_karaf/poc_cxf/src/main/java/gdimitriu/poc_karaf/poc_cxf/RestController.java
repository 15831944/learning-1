package gdimitriu.poc_karaf.poc_cxf;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

@Path("/cxf_test")
public class RestController {

    @Path("/info")
    @GET
    public String getInfo() {
        return "server is alive";
    }

    @Path("json")
    @GET
    @Produces({MediaType.APPLICATION_JSON})
    public JacksonTest jsonTest() {
        JacksonTest test = new JacksonTest("server","Server is alive");
        return test;
    }
}
