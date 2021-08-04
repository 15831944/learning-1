package diJava9.factoryPatern;

import diJava9.withInterfaces.*;

public class FetchDataFactory {
    public static IFetchData getFetchData(String type) {
        IFetchData fetchData = null;
        if("FROM_DB".equalsIgnoreCase(type)) {
            fetchData = new FetchDatabase();
        } else if ("FROM_WS".equalsIgnoreCase(type)) {
            fetchData = new FetchWebService();
        } else {
            return null;
        }
        return fetchData;
    }
}
