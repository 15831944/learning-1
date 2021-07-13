package com.example.bookpub;

import io.cucumber.junit.Cucumber;
import io.cucumber.junit.CucumberOptions;
import org.junit.runner.RunWith;

@RunWith(Cucumber.class)
@CucumberOptions(plugin={"pretty", "html:build/reports/cucumber"},
        glue={"cucumber.api.spring", "classpath:com.example.bookpub"},
        monochrome =  true)
public class RunCukeTests {
}
