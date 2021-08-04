package aop.service;

public class HRService {
    public void showHolidayList() {
        System.out.println("This is holiday list method ...");
    }

    public void showMyLeave() throws Exception {
        System.out.println("Showing employee leaves...");
        throw new Exception();
    }
    public String showHolidayListWithData() {
        System.out.println("This is holiday list method with data...");
        return "holidayList";
    }
}
