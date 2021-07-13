/**
 * 
 */
package certification.nio2;

import java.io.File;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.UserPrincipal;

/**
 * @author Gabriel Dimitriu
 *
 */
public class PathExamples {

	/**
	 * 
	 */
	public PathExamples() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = FileSystems.getDefault().getPath("d:", "tmp");
		System.out.println(path.toAbsolutePath());
		try {
			path = Paths.get(new URI("file:///d:/tmp/chappy"));
		} catch (URISyntaxException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(path.toAbsolutePath());
		/*
		try {
			FileSystem fileSystem = FileSystems.getFileSystem(new URI("https://www.selikoff.net")); //could not find provider for https
			path = fileSystem.getPath("category", "aws");
			System.out.println(path.toAbsolutePath());
		} catch (URISyntaxException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		*/
		File file = path.toFile();
		System.out.println("is directory:" + file.isDirectory());
		for (int i = 0; i < path.getNameCount(); i++) {
			System.out.println(" Element i=" + i + " is " + path.getName(i));
		}
		System.out.println("Root is " + path.getRoot());
		path = Paths.get("../tmp");
		for (int i = 0; i< path.getNameCount(); i++) {
			System.out.println(" Element i=" + i + " is " + path.getName(i));
		}
		Path path1 = Paths.get("E:\\data");
		Path path2 = Paths.get("E:\\user\\home");
		Path relativePath = path1.relativize(path2);
		System.out.println(relativePath);
		System.out.println(path1.resolve(relativePath));
		System.out.println(path1.resolve(relativePath).normalize());
		try {
			UserPrincipal owner = FileSystems.getDefault().getUserPrincipalLookupService().lookupPrincipalByName("gdimitriu");
			System.out.println(owner.getName());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			path = Paths.get("d:\\tmp");
			Files.list(path).filter(p -> !Files.isDirectory(p)).map(p -> p.toAbsolutePath()).forEach(System.out::println);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
