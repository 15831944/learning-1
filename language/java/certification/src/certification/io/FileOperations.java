/**
 * 
 */
package certification.io;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

/**
 * @author Gabriel Dimitriu
 *
 */
public class FileOperations {

	private String parentDirectory = null;
	private File parentDirectoryFile = null;
	private List<String> filesToCreate = null;
	private List<String> directoriesToCreate = null;
	
	/**
	 * 
	 */
	public FileOperations(final String parentDirectory) {
		this.parentDirectory = parentDirectory;
		filesToCreate = Arrays.asList("fist.txt", "second.txt", "third.txt");
		directoriesToCreate = Arrays.asList("dir1", "dir2", "dir1_1", "dir2_1");
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("You should call with absolute parent directory !");
			System.exit(-1);
		}
		FileOperations files = new FileOperations(args[0]);
		try {
			files.checkParentDirectory();
		} catch (Exception e) {
			System.err.println("Parent directory invalid " + e.getLocalizedMessage());
			System.exit(-1);
		}
		try {
			files.createAndDisplayFiles();
		} catch (Exception e) {
			System.err.println("Exception on files " + e.getLocalizedMessage());
		}
		files.deleteAllFiles();
		System.out.println("\nCreate Recursive and delete files and directories !");
		files.createRecursiveDirectoryAndFiles();
		files.printAllFiles();
		files.deleteAllDirectoriesAndFiles();
	}

	private void printAllFiles() {
		printRecursiveAllFiles(parentDirectoryFile);
	}

	private void printRecursiveAllFiles(File directory) {
		File[] files = directory.listFiles();
		for (File file : files) {
			if (file.isDirectory()) {
				printRecursiveAllFiles(file);
			} else {
				System.out.println(file.getAbsolutePath());
			}
		}
	}

	private void deleteAllDirectoriesAndFiles() {
		deleteRecursiveDirectoryAndFiles(parentDirectoryFile);
	}

	private void deleteRecursiveDirectoryAndFiles(final File directory) {
		if (directory.isDirectory()) {
			File[] files = directory.listFiles();
			for (File file : files) {
				deleteRecursiveDirectoryAndFiles(file);
			}
		}
		directory.delete();
	}

	private void createRecursiveDirectoryAndFiles() {
		File directory = null;
		for (String name : directoriesToCreate) {
			if (name.contains("_")) {
				String path = name.substring(0, name.indexOf('_')) + "/" + name;
				directory = new File(parentDirectoryFile, path);
				directory.mkdirs();
			} else {
				directory = new File(parentDirectoryFile, name);
				directory.mkdir();
			}
			for (String file : filesToCreate) {
				try {
					new File(directory, file).createNewFile();
				} catch (IOException e) {
					System.err.println("File=" + file + " could not be created in directory " 
							+ directory.getAbsolutePath() + " because " 
							+ e.getLocalizedMessage());
				}
			}
		}
		
	}

	private void deleteAllFiles() {
		for (File file : parentDirectoryFile.listFiles()) {
			file.delete();
		}
	}

	private void createAndDisplayFiles() throws Exception{
		if (parentDirectoryFile == null) {
			throw new Exception("parentFile directory is null !");
		}
		for (String fileName : filesToCreate) {
			new File(parentDirectoryFile, fileName).createNewFile();
		}
		File[] files = parentDirectoryFile.listFiles();
		for (File file : files) {
			System.out.println(file.getAbsolutePath() + " : " + file.getName());
		}
	}

	private void checkParentDirectory() throws Exception {
		if (parentDirectory.isEmpty()) {
			System.err.println("You shoudl call with a not empty parent directory !");
			System.exit(-1);
		}
		parentDirectoryFile = new File(parentDirectory);
		if (!parentDirectoryFile.exists()) {
			parentDirectoryFile.mkdirs();
		} else if (!parentDirectoryFile.isDirectory()) {
			throw new Exception("Parent directory is not a directory!");
		}
	}

}
