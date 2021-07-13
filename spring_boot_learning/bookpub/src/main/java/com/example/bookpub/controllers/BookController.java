package com.example.bookpub.controllers;

import com.example.bookpub.Book;
import com.example.bookpub.Publisher;
import com.example.bookpub.Reviewer;
import com.example.bookpub.editors.IsbnEditor;
import com.example.bookpub.model.Isbn;
import com.example.bookpub.repository.BookRepository;
import com.example.bookpub.repository.PublisherRepository;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.Collections;
import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/books")
public class BookController {
    @Autowired
    private BookRepository bookRepository;

    @Autowired
    private PublisherRepository publisherRepository;

    @RequestMapping(value = "", method = RequestMethod.GET)
    @HystrixCommand(fallbackMethod = "getEmptyBooksList")
    public Iterable<Book> getAllBooks() {
        return bookRepository.findAll();
        // this is to test the circuit breaker
        //throw new RuntimeException("Books service Not Available");
    }

    public Iterable<Book> getEmptyBooksList() {
        return Collections.emptyList();
    }

    @RequestMapping(value = "/{isbn}", method = RequestMethod.GET)
    public Book getBook(@PathVariable String isbn) {
        return bookRepository.findBookByIsbn(isbn);
    }

    @InitBinder
    public void initBinder(WebDataBinder binder) {
        binder.registerCustomEditor(Isbn.class, new IsbnEditor());
    }

    @RequestMapping(value = "/{isbn}/reviewers", method = RequestMethod.GET)
    public List<Reviewer> getReviewers(@PathVariable("isbn") Book book) {
        return  book.getReviewers();
    }

    @RequestMapping(value = "/session", method =  RequestMethod.GET)
    public String getSessionId(HttpServletRequest request) {
        return request.getSession().getId();
    }

    @RequestMapping(value = "/publishers/{id}", method = RequestMethod.GET)
    public List<Book> getPublishers(@PathVariable("id") Long id) {
        Optional<Publisher> publisher = publisherRepository.findById(id);
        return publisher.get().getBooks();
    }
}
