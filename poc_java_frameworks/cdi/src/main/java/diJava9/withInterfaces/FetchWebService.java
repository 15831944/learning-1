package diJava9.withInterfaces;

import java.util.ArrayList;
import java.util.List;

public class FetchWebService implements  IFetchData{
    public List<Object[]> fetchData() {
        List<Object[]> dateFromWebService = new ArrayList<Object[]>();
        System.out.println("Called FetchWebService");
        return dateFromWebService;
    }
}
