package certification.ioOperations;

import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;

public class RWOperations {

	public static void main(String[] args) {
		fileRW();
		bufferedRW();
		printRW();
	}

	private static void fileRW() {
		System.out.println("fileRW");
		File file = new File("file.dat");
		try {
			FileWriter fw = new FileWriter(file);
			fw.write("this is a test\n");
			fw.write("this is the second line\n");
			fw.flush();
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			if(file.exists()) {
				FileReader fr = new FileReader(file);
				char[] data = new char[256]; 
				int reads = fr.read(data);
				for (int i = 0; i < reads; i++) {
					System.out.print(data[i]);
				}
				fr.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		file.delete();
	}
	
	private static void bufferedRW() {
		System.out.println("bufferedRW");
		File file = new File("file.dat");
		BufferedWriter bw = null;
		try {
			bw = new BufferedWriter(new FileWriter(file));
			bw.write("this is the first line");
			bw.newLine();
			bw.write("this is the second line");
			bw.newLine();
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				bw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			String str = null;
			str = br.readLine();
			while (str != null) {
				System.out.print(str + "\n");
				str = br.readLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		file.delete();
	}
	
	private static void printRW() {
		
		System.out.println("printRW");
		File file = new File("file.dat");
		if (file.exists()) {
			file.delete();
		}
		
		try (PrintWriter pw = new PrintWriter(file)) {
			pw.format("%s\n", "this is the first line");
			pw.format("%s\n", "this is the second line");
			pw.flush();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			String str = null;
			str = br.readLine();
			while (str != null) {
				System.out.println(str);
				str = br.readLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		file.delete();
	}
}
