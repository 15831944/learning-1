package diJava9.withInterfaces;

import java.io.File;
import java.util.List;

public class ExportHtml implements  IExportData {
    public File exportData(List<Object[]> listData) {
        System.out.println("Called ExportHtml");
        return null;
    }
}
