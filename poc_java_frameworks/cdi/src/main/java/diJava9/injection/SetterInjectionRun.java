package diJava9.injection;

import diJava9.withInterfaces.ExportHtml;
import diJava9.withInterfaces.FetchWebService;

public class SetterInjectionRun {
    public static void main(String...args) {
        BalanceSheetSetterInjection balance = new BalanceSheetSetterInjection();
        balance.setExportData(new ExportHtml());
        balance.setFetchData(new FetchWebService());
        balance.generateBalanceSheet();
    }
}
