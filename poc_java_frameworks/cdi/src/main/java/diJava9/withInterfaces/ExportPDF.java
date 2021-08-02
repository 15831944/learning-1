package diJava9.withInterfaces;

import java.io.File;
import java.util.List;

public class ExportPDF implements  IExportData {
    public File exportData(List<Object[]> listData) {
        System.out.println("Called ExportPDF");
        return null;
    }
}
