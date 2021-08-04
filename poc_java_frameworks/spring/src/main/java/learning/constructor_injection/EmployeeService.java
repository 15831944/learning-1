package learning.constructor_injection;

public class EmployeeService {
    private Logger log;

    public EmployeeService(Logger logger) {
        this.log = logger;
    }
    public void showEmployeeName() {
        log.info("showEmployeeName method is called ...");
        log.debug("This is the debug point.");
        log.error("This is the error where exception was thrown...");
    }
}
