/**
 * 
 */
package certification.nio2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributeView;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;

/**
 * @author Gabriel Dimitriu
 *
 */
public class BasicFileAttributesViewExample {

	/**
	 * 
	 */
	public BasicFileAttributesViewExample() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("You should call with path argument!");
			System.exit(-1);
		}
		Path path = Paths.get(args[0]);
		BasicFileAttributeView view = Files.getFileAttributeView(path, BasicFileAttributeView.class);
		try {
			BasicFileAttributes data = view.readAttributes();
			FileTime lastModifiedTime = FileTime.fromMillis(data.lastModifiedTime().toMillis() + 10_000);
			view.setTimes(lastModifiedTime, null, null);
		} catch (IOException e) {
			System.err.println("Could not get the attributes for path !" + e.getLocalizedMessage());
		}
	}
}
