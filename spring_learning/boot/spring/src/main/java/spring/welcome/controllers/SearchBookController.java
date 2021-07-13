package spring.welcome.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
import spring.welcome.beans.Book;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Controller
public class SearchBookController {
    @RequestMapping(value = "searchBooks.htm", method= RequestMethod.GET)
    public ModelAndView searchBooks(Map<String, Object> model, @RequestParam("author") String authorName) {
        List<Book> books = new ArrayList<>();
        books.add(new Book("Learning Modular Java programming", 9781235, "packt pub publication",
                800, "explore the power of modular programming", authorName));
        books.add(new Book("Learning Modular Java programming second edition", 9781237, "packt pub publication",
                800, "explore the power of modular programming", authorName));
        model.put("auth_name", authorName);
        return new ModelAndView("display", "book_list", books);
    }
}
