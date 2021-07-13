/**
 * 
 */
package first_spring.destruction;

import java.io.File;

import org.springframework.beans.factory.InitializingBean;
import org.springframework.context.support.GenericXmlApplicationContext;

/**
 * @author Gabriel Dimitriu
 *
 */
public class DestructiveBean implements InitializingBean {

	private File file;
	private String filePath;
	
	/* (non-Javadoc)
	 * @see org.springframework.beans.factory.InitializingBean#afterPropertiesSet()
	 */
	@Override
	public void afterPropertiesSet() throws Exception {
		System.out.println("Initializing Bean");
		if (filePath == null) {
			throw new IllegalArgumentException("You must specify the filePath property of " + DestructiveBean.class);
		}
		this.file = new File(filePath);
		this.file.createNewFile();
		
		System.out.println("File exists: " + file.exists());
	}
	
	public void destroy() {
		System.out.println("Destroying Bean");
		if(!file.delete()) {
			System.err.println("ERROR: failed to delete file.");
		}
		System.out.println("File exists: " + file.exists());
	}

	/**
	 * @param filePath the filePath to set
	 */
	public void setFilePath(String filePath) {
		this.filePath = filePath;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("destructivebean.xml");
		ctx.refresh();
		DestructiveBean bean = (DestructiveBean) ctx.getBean("destructiveBean");
		System.out.println("Calling destroy()");
		ctx.destroy();
		System.out.println("Called destroy()");
		ctx.close();
	}

}
