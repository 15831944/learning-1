package diJava9.factoryPatern;

import java.util.List;
import diJava9.withInterfaces.IExportData;
import diJava9.withInterfaces.IFetchData;

public class BalanceSheet {
    private IExportData exportDataObj = null;
    private IFetchData fetchDataObj = null;

    public void configureFetchData(String type) {
        this.fetchDataObj = FetchDataFactory.getFetchData(type);
    }

    public void configureExportData(String type) {
        this.exportDataObj = ExportDataFactory.getExportData(type);
    }

    public Object generateBalanceSheet() {
        List<Object[]> dataLst = fetchDataObj.fetchData();
        return exportDataObj.exportData(dataLst);
    }
}
