package diJava9.injection.interfaceInjection;

import diJava9.withInterfaces.IExportData;
import diJava9.withInterfaces.IFetchData;

import java.util.List;

public class BalanceSheetInterfaceInjection implements IFetchAndExport {
    private IExportData exportData = null;
    private IFetchData fetchData = null;

    public Object generateBalanceSheet() {
        List<Object[]> dataLst = fetchData.fetchData();
        return exportData.exportData(dataLst);
    }

    @Override
    public void setFetchData(IFetchData fetchData) {
        this.fetchData = fetchData;
    }

    @Override
    public void setExportData(IExportData exportData) {
        this.exportData = exportData;
    }
}
