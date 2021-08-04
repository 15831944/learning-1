package learning.autowiring;

public class AccountService {
    private UserService userService = null;

    public void setUserService(UserService userService) {
        this.userService = userService;
    }
    public void processUserService() {
        if(this.userService != null) {
            this.userService.getUserDetail();
        }
    }
}
