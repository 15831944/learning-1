package diJava9.injection;

import diJava9.withInterfaces.IExportData;
import diJava9.withInterfaces.IFetchData;

import java.util.List;

public class BalanceSheetSetterInjection {
    private IExportData exportData = null;
    private IFetchData fetchData = null;

    public void setExportData(IExportData exportDataObj) {
        this.exportData = exportDataObj;
    }

    public void setFetchData(IFetchData fetchDataObj) {
        this.fetchData = fetchDataObj;
    }

    public Object generateBalanceSheet() {
        List<Object[]> dataLst = fetchData.fetchData();
        return exportData.exportData(dataLst);
    }
}
