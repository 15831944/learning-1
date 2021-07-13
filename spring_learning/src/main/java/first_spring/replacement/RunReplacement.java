/**
 * 
 */
package first_spring.replacement;

import org.springframework.context.support.GenericXmlApplicationContext;
import org.springframework.util.StopWatch;

/**
 * @author Gabriel Dimitriu
 *
 */
public class RunReplacement {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("replacementcontext.xml");
		ctx.refresh();

		ReplacementTarget replacementTarget = (ReplacementTarget) ctx.getBean("replacementTarget");
		ReplacementTarget standardTarget = (ReplacementTarget) ctx.getBean("standardTarget");
	
		displayInfo(standardTarget);
		displayInfo(replacementTarget);
		ctx.close();
	}
	
	private static void displayInfo(ReplacementTarget target) {
		System.out.println(target.formatMessage("Hello world!"));
		
		StopWatch stopWatch = new StopWatch();
		stopWatch.start("pefTest");
		for (int x = 0 ; x < 100000; x++) {
			String out = target.formatMessage("foo");
		}
		stopWatch.stop();
		
		System.out.println("100000 gets took " + stopWatch.getTotalTimeMillis() + " ms.");
	}
}
