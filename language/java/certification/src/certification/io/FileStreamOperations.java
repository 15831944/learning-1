/**
 * 
 */
package certification.io;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Gabriel Dimitriu
 *
 */
public class FileStreamOperations {

	private String parentDirectory = null;
	private File parentFileDirectory = null;
	private final String fileName = "test.txt";
	private List<String> data = Arrays.asList("first data", "second data");
	/**
	 * 
	 */
	public FileStreamOperations(final String parentDirectory) {
		this.parentDirectory = parentDirectory;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("You should call with parent directory");
			System.exit(-1);
		}
		FileStreamOperations streamOp = new FileStreamOperations(args[0]);
		streamOp.validateAndOpenDirectory();
		try {
			streamOp.writeData();
			streamOp.readAndPrintData(streamOp.getfileName());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			streamOp.deleteData();
			System.exit(-1);
		}
		try {
			streamOp.copyFile(streamOp.getfileName(), "copy_" + streamOp.getfileName());
			System.out.println("Data from copied file !");
			streamOp.readAndPrintData("copy_" + streamOp.getfileName());
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			streamOp.copyBufferedFile(streamOp.getfileName(), "copy1_" + streamOp.getfileName());
			System.out.println("Data from buffered copied file !");
			streamOp.readAndPrintData("copy1_" + streamOp.getfileName());
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			streamOp.copyTextFile(streamOp.getfileName(), "copy2_" + streamOp.getfileName());
			System.out.println("Data from buffered copied file !");
			streamOp.readAndPrintData("copy2_" + streamOp.getfileName());
		} catch (IOException e) {
			e.printStackTrace();
		}
		streamOp.deleteData();
		File toDelFile = new File(args[0], "copy_" + streamOp.getfileName());
		if (toDelFile.exists()) {
			toDelFile.delete();
		}
		toDelFile = new File(args[0], "copy1_" + streamOp.getfileName());
		if (toDelFile.exists()) {
			toDelFile.delete();
		}
		toDelFile = new File(args[0], "copy2_" + streamOp.getfileName());
		if (toDelFile.exists()) {
			toDelFile.delete();
		}
	}

	private void copyFile(final String source, final String destination) throws IOException{
		File sourceFile = new File(parentFileDirectory, source);
		File destinationFile = new File(parentFileDirectory, destination);
		if (!sourceFile.exists()) {
			return;
		}
		if (destinationFile.exists()) {
			destinationFile.delete();
			destinationFile.createNewFile();
		}
		try (InputStream in = new FileInputStream(sourceFile); OutputStream out = new FileOutputStream(destinationFile);) {
			int b;
			while((b = in.read()) != -1) {
				out.write(b);
				out.flush();
			}
		}
	}
	
	private void copyBufferedFile(final String source, final String destination) throws IOException {
		File sourceFile = new File(parentFileDirectory, source);
		if (!sourceFile.exists()) {
			return;
		}
		File destinationFile = new File(parentFileDirectory, destination);
		if (destinationFile.exists()) {
			destinationFile.delete();
			destinationFile.createNewFile();
		}
		try (InputStream in = new BufferedInputStream(new FileInputStream(sourceFile));
				OutputStream out = new BufferedOutputStream(new FileOutputStream(destinationFile))) {
			byte[] buffer = new byte[1024];
			int len = 0;
			while((len = in.read(buffer)) > 0) {
				out.write(buffer, 0, len);
				out.flush();
			}
		}
	}
	
	private String getfileName() {
		return fileName;
	}

	private void deleteData() {
		File dataFile = new File(parentFileDirectory, fileName);
		if (dataFile.exists()) {
			dataFile.delete();
		}
	}
	
	private void validateAndOpenDirectory() {
		parentFileDirectory = new File(parentDirectory);
		if (!parentFileDirectory.exists()) {
			parentFileDirectory.mkdir();
		}
		if (!parentFileDirectory.isDirectory()) {
			System.err.println("path introduced is not a directory = " + parentDirectory);
			System.exit(-1);
		}
		if (parentFileDirectory.listFiles().length != 0) {
			for (File file : parentFileDirectory.listFiles()) {
				if (file.getName().equals(fileName)) {
					file.delete();
					break;
				}
			}
		}
	}

	private void writeData() throws IOException {
		File dataFile = new File(parentFileDirectory, fileName);
		if (dataFile.exists()) {
			dataFile.delete();
			dataFile.createNewFile();
		}
		BufferedWriter buffer = new BufferedWriter(new FileWriter(dataFile));
		for (String str : data) {
			buffer.write(str);
			buffer.write(System.lineSeparator());
		}
		buffer.flush();
		buffer.close();
	}
	
	private void readAndPrintData(final String localfileName) throws IOException {
		File dataFile = new File(parentFileDirectory, localfileName);
		if (!dataFile.exists()) {
			System.out.println("File was not created at first step !");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(dataFile));
		String data = reader.readLine();
		while(data!=null) {
			System.out.println(data);
			data = reader.readLine();
		}
		reader.close();
	}
	
	private void copyTextFile(final String source, final String destination) throws IOException {
		File sourceFile = new File(parentFileDirectory, source);
		if (!sourceFile.exists()) {
			return;
		}
		File destinationFile = new File(parentFileDirectory, destination);
		if (destinationFile.exists()) {
			destinationFile.delete();
			destinationFile.createNewFile();
		}
		List<String> data = readTextFile(sourceFile);
		System.out.println("Data from text file!");
		for (String str : data) {
			System.out.println(str);
		}
		writeTextData(destinationFile, data);
	}
	
	private void writeTextData(final File file, List<String> data) throws IOException{
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
			for (String str : data) {
				writer.write(str);
				writer.newLine();
			}
		}
	}
	private List<String> readTextFile(final File file) throws IOException {
		List<String> data = new ArrayList<>();
		try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
			String s;
			while((s = reader.readLine()) != null) {
				data.add(s);
			}
		}
		return data;
	}
}
