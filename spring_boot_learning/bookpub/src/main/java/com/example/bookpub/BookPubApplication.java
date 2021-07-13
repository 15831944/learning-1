package com.example.bookpub;

import com.example.bookpubstarter.dbcount.EnableDbCounting;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.actuate.autoconfigure.web.ManagementContextConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.circuitbreaker.EnableCircuitBreaker;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.netflix.ribbon.RibbonClient;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.FilterType;
import org.springframework.scheduling.annotation.EnableScheduling;
import sun.misc.Signal;
import sun.misc.SignalHandler;

@ComponentScan(excludeFilters = @ComponentScan.Filter(type = FilterType.ANNOTATION,
		classes = ManagementContextConfiguration.class))
@SpringBootApplication
@EnableScheduling
@EnableDbCounting
@EnableDiscoveryClient
@EnableFeignClients
@RibbonClient(name = "BookPub-service", configuration = LocalRibbonClientConfiguration.class)
@EnableCircuitBreaker
public class BookPubApplication {

	private Log logger = LogFactory.getLog(getClass());
	public static void main(String[] args)
	{
		Reloader reloader = new Reloader();
		Signal.handle(new Signal("HUP"), reloader);
		SpringApplication.run(BookPubApplication.class, args);
	}

	static class Reloader implements SignalHandler {

		@Override
		public void handle(Signal signal) {
			System.out.println("Reloading data...!!!");
		}
	}

	@Bean
	public StartupRunner schedulerRunner() {
		return new StartupRunner();
	}

/* does not allowed to have bean and annotation in the same time
	@Bean
	public DbCountRunner dbCountRunner(Collection<CrudRepository> repositories) {
		return new DbCountRunner(repositories) {
			@Override
			public void run(String...args) throws Exception {
				logger.info("Manually Declared DbCountRunner");
			}
		};
	} */

	@Bean
	public CommandLineRunner configValuePrinter(@Value("${my.config.value:}") String configValue) {
		return args -> LogFactory.getLog(getClass()).info("Value of my.config.value property is : " + configValue);
	}
}
