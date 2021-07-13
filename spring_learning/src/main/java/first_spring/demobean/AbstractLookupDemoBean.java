/**
 * 
 */
package first_spring.demobean;

/**
 * @author Gabriel Dimitriu
 *
 */
public abstract class AbstractLookupDemoBean implements DemoBean {
	public abstract MyHelper getMyHelper();
	
	@Override
	public void someOperation() {
		getMyHelper().doSomething();
	}
}
