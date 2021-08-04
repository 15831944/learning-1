package diJava9.injection.interfaceInjection;

import diJava9.withInterfaces.IExportData;
import diJava9.withInterfaces.IFetchData;

public interface IFetchAndExport {
    void setFetchData(IFetchData fetchData);
    void setExportData(IExportData exportData);
}
