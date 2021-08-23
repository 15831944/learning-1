package certification.io.ocjp;

import java.io.File;

public class ReadFileInformation {
    public static void main(String...args) {
        if (args.length != 1) {
            System.err.println("Call with filepath argument");
            System.exit(-1);
        }
        File file = new File(args[0]);
        System.out.println("File Exists: " + file.exists());
        if (file.exists()) {
            System.out.println("Absolute Path: " + file.getAbsolutePath());
            System.out.println("Is directory: " + file.isDirectory());
            System.out.println("Parent Path: " + file.getParent());
            if (file.isFile()) {
                System.out.println("File size:" + file.length());
                System.out.println("File LastModified: " + file.lastModified());
            } else {
                for(File subfile: file.listFiles())
                    System.out.println("\t" + subfile.getName());
            }
        }
    }
}
