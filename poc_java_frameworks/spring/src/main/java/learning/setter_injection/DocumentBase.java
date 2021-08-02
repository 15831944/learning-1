package learning.setter_injection;

public class DocumentBase {
    private DocFinder docFinder;
    private String buildNo;

    public void setBuildNo(String buildNo) {
        this.buildNo = buildNo;
    }

    public void setDocFinder(DocFinder finder) {
        this.docFinder = finder;
    }
    public void performSearch() {
        System.out.println("Performing search for buildNo:" + buildNo);
        this.docFinder.doFind();
    }
}
