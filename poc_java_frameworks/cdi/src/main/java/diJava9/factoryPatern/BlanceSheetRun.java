package diJava9.factoryPatern;


public class BlanceSheetRun {
    public static void main(String...args) {
        BalanceSheet balance = new BalanceSheet();
        balance.configureFetchData("FROM_WS");
        balance.configureExportData("TO_PDF");
        balance.generateBalanceSheet();
    }
}
