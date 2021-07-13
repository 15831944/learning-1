package first_spring.concert;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

@Configuration
@ComponentScan
@EnableAspectJAutoProxy
public class AudienceConfiguration {

	@Bean
	public Audience1 audience1() {
		return new Audience1();
	}
	
	@Bean
	public Audience2 audience2() {
		return new Audience2();
	}
}
