package diJava9.injection;

import diJava9.withInterfaces.ExportPDF;
import diJava9.withInterfaces.FetchDatabase;

public class ConstructorInjectionRun {
    public static void main(String...args) {
        BalanceSheetConstructorInjection balance = new BalanceSheetConstructorInjection(new ExportPDF(), new FetchDatabase());
        balance.generateBalanceSheet();
    }
}
