package diJava9.withInterfaces;

import java.util.List;

public class BalanceSheet {
    private IExportData exportDataObj = null;
    private IFetchData fetchDataObj = null;

    public void setExportDataObj(IExportData exportDataObj) {
        this.exportDataObj = exportDataObj;
    }

    public void setFetchDataObj(IFetchData fetchDataObj) {
        this.fetchDataObj = fetchDataObj;
    }

    public Object generateBalanceSheet() {
        List<Object[]> dataLst = fetchDataObj.fetchData();
        return exportDataObj.exportData(dataLst);
    }
}
