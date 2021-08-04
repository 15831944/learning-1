package learning.springbootweb.controller;
import learning.springbootweb.beans.PrototypeBeanScope;
import learning.springbootweb.beans.RequestBeanScope;
import learning.springbootweb.beans.SessionBeanScope;
import learning.springbootweb.beans.SingletonBeanScope;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class StudentController {

    public StudentController() {
        System.out.println(":::::::::::Student Controller Initialized :::::::::::::");
    }
    @Autowired
    PrototypeBeanScope prototypeBeanScope;
    @Autowired
    SessionBeanScope sessionBeanScope;
    @Autowired
    RequestBeanScope requestBeanScope;
    @Autowired
    SingletonBeanScope singletonBeanScope;

    @RequestMapping("/")
    public String index() {
        sessionBeanScope.printClassDetail();
        requestBeanScope.printAddress();

        return " Greetings !!!";
    }
}
