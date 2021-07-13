package first_spring.concert;

import org.springframework.stereotype.Component;

@Component
public class ConcertClasic implements Performance {

	public void perform() {
		System.out.println("perform good");
	}

}
