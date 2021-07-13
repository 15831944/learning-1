/**
 * 
 */
package first_spring.demobean;

import org.springframework.context.support.GenericXmlApplicationContext;
import org.springframework.util.StopWatch;

/**
 * @author Gabriel Dimitriu
 *
 */
public class RunDemoBean {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("demobeancontext.xml");
		ctx.refresh();
		
		DemoBean abstractBean = (DemoBean) ctx.getBean("abstractLookupBean");
		DemoBean standardBean = (DemoBean) ctx.getBean("standardLookupBean");
		
		displayInfo(standardBean);
		displayInfo(abstractBean);
		ctx.close();
	}

	private static void displayInfo(DemoBean bean) {
		MyHelper helper1 = bean.getMyHelper();
		MyHelper helper2 = bean.getMyHelper();
		
		System.out.println("Helper Instances the same?: " + (helper1 == helper2));
		
		StopWatch stopWatch = new StopWatch();
		stopWatch.start("lookupDemo");
		for (int x = 0 ; x < 100000; x++) {
			MyHelper helper = bean.getMyHelper();
			helper.doSomething();
		}
		stopWatch.stop();
		
		System.out.println("100000 gets took " + stopWatch.getTotalTimeMillis() + " ms.");
	}

}
