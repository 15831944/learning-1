/**
 * 
 */
package certification.iostreams;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.stream.Collectors;

/**
 * @author Gabriel
 *
 */
public class ConversionOfStreams {

	private InputStream is = null;
	private OutputStream os = null;
	/**
	 * 
	 */
	public ConversionOfStreams() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ConversionOfStreams conv = new ConversionOfStreams();
		conv.populateOS();
		conv.convert();
//		conv.getIS();
		conv.closeAll();
	}
	
	public void populateOS() {
		os = new ByteArrayOutputStream2();
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
		try {
			writer.write("test test test");
			writer.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void convert() {
		is = new ByteArrayInputStream(((ByteArrayOutputStream2) os).buf());
		System.out.println(new BufferedReader(new InputStreamReader(is))
		  .lines().collect(Collectors.joining("\n")));
	}
	
	public void closeAll() {
		try {
			os.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			is.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
