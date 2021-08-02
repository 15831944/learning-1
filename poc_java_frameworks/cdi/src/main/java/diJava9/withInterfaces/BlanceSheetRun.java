package diJava9.withInterfaces;

public class BlanceSheetRun {
    public static void main(String...args) {
        BalanceSheet balance = new BalanceSheet();
        balance.setExportDataObj(new ExportPDF());
        balance.setFetchDataObj(new FetchDatabase());
        balance.generateBalanceSheet();
    }
}
