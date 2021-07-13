package spring.welcome.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import spring.welcome.beans.Book;

import java.util.ArrayList;
import java.util.List;

@Controller
public class AddBookController {
    @ModelAttribute("priceList")
    public List<Integer> addPrices() {

        List<Integer> prices=new ArrayList<Integer>();
        prices.add(300);
        prices.add(350);
        prices.add(400);
        prices.add(500);
        prices.add(550);
        prices.add(600);

        return prices;
    }

    @RequestMapping("/showBookForm.htm")
    public ModelAndView showBookForm(ModelMap map) throws Exception{
        Book book = new Book();
        map.addAttribute(book);
        return new ModelAndView("bookForm");
    }

    @RequestMapping("/addBook.htm")
    public ModelAndView addBook(@ModelAttribute("book") Book book, BindingResult bindingResult)
            throws Exception {

        if(bindingResult.hasErrors())
        {
            return new ModelAndView("bookForm");
        }

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("display");
        //later on the list will be fetched from the table
        List<Book> books=new ArrayList();
        books.add(book);
        modelAndView.addObject("book_list",books);
        modelAndView.addObject("auth_name",book.getAuthor());
        return modelAndView;
    }

}
