package diJava9.injection.interfaceInjection;

import diJava9.withInterfaces.ExportPDF;
import diJava9.withInterfaces.FetchDatabase;

public class BalanceSheetInterfaceInjectionRun {
    public static void main(String...args) {
        BalanceSheetInterfaceInjection balance = new BalanceSheetInterfaceInjection();
        balance.setExportData(new ExportPDF());
        balance.setFetchData(new FetchDatabase());
        balance.generateBalanceSheet();
    }
}
