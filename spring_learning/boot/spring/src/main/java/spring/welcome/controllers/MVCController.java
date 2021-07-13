package spring.welcome.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import java.util.Map;

@Controller
public class MVCController {
    @RequestMapping(value = "welcomeController.htm", method=RequestMethod.GET)
    public ModelAndView welcome() {
        String welcome_message = "Welcome to the book library !";
        return new ModelAndView("welcome", "message", welcome_message);
    }
    @RequestMapping("/")
    public String home(Map<String, Object> model) {
        return "index";
    }

    @RequestMapping("/my")
    public String firstPage(Map<String, Object> model) {
        model.put("message", "HowToDoInJava Reader !!");
        return "firstPage";
    }

    @RequestMapping("/my/next")
    public String nextPage(Map<String, Object> model) {
        model.put("message", "You are in new page !!");
        return "nextPage";
    }
}
