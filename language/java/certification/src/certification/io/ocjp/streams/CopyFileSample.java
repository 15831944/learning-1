package certification.io.ocjp.streams;

import java.io.*;

public class CopyFileSample {
    public static void copy(File source, File destination) throws IOException {
        try (InputStream in = new FileInputStream(source);
             OutputStream out = new FileOutputStream(destination)) {
            int b;
            while((b = in.read()) != -1)
                out.write(b);
        }
    }

    public static void copyBuffered(File source, File destination) throws IOException {
        try (InputStream in = new BufferedInputStream(new FileInputStream(source));
        OutputStream out = new BufferedOutputStream(new FileOutputStream(destination))) {
            byte[] buffer = new byte[1024];
            int lengthRead;
            while((lengthRead = in.read(buffer)) > 0) {
                out.write(buffer,0, lengthRead);
                out.flush();
            }
        }
    }

    public static void main(String...args) throws IOException {
        if (args.length != 2) {
            System.out.println("Call with inputFile outputFile");
            System.exit(-1);
        }
        File source = new File(args[0]);
        File destination = new File(args[1]);
        if (source.exists() && source.isFile()) {
            copy(source,destination);
        }
    }
}
