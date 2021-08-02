package diJava9.withInterfaces;

import java.util.ArrayList;
import java.util.List;

public class FetchDatabase implements IFetchData{

    public List<Object[]> fetchData() {
        List<Object[]> dataFromDB = new ArrayList<Object[]>();
        System.out.println("Called FetchDatabase");
        return dataFromDB;
    }
}
