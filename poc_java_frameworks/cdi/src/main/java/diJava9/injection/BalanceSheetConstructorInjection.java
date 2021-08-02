package diJava9.injection;

import diJava9.withInterfaces.IExportData;
import diJava9.withInterfaces.IFetchData;

import java.util.List;

public class BalanceSheetConstructorInjection {
    private IExportData exportDataObj = null;
    private IFetchData fetchDataObj = null;

    public BalanceSheetConstructorInjection(IExportData exportDataObj, IFetchData fetchDataObj) {
        this.exportDataObj = exportDataObj;
        this.fetchDataObj = fetchDataObj;
    }

    public Object generateBalanceSheet() {
        List<Object[]> dataLst = fetchDataObj.fetchData();
        return exportDataObj.exportData(dataLst);
    }
}
