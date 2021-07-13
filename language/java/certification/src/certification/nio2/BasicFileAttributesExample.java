/**
 * 
 */
package certification.nio2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;

/**
 * @author Gabriel Dimitriu
 *
 */
public class BasicFileAttributesExample {

	/**
	 * 
	 */
	public BasicFileAttributesExample() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("You should call with path to a file or directory!");
			System.exit(-1);
		}
		Path path = Paths.get(args[0]);
		try {
			BasicFileAttributes data = Files.readAttributes(path, BasicFileAttributes.class);
			System.out.println("Is path a directory ? "  + data.isDirectory());
			System.out.println("Is path a regular file ? " + data.isRegularFile());
			System.out.println("Is path a symbolic link ? " + data.isSymbolicLink());
			System.out.println("Path not a file, directory, nor symbolic link ?" + data.isOther());
			System.out.println("Size in bytes: " + data.size());
			System.out.println("Creation time : " + data.creationTime());
			System.out.println("Last modified on : " + data.lastModifiedTime());
			System.out.println("Last acceessed time : " + data.lastAccessTime());
			System.out.println("Unique file identifier (if available) " + data.fileKey());
		} catch (IOException e) {
			System.out.println("Attributes could not be read ! " + e.getLocalizedMessage());
			System.exit(-1);
		}
	}

}
