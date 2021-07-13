package com.example.bookpub.api;

import com.example.bookpub.Book;
import org.springframework.cloud.netflix.ribbon.RibbonClient;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@FeignClient("http://BookPub")
@RibbonClient(name = "BookPub-service")
public interface BookPubClient {
    @RequestMapping(value = "/books/{isbn}", method = RequestMethod.GET)
    public Book findBookByIsbn(@PathVariable("isbn") String isbn);
}
