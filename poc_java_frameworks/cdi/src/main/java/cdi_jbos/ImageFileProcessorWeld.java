package cdi_jbos;

import cdi_jbos.named.ImageFileProcessorNamed;
import cdi_jbos.qualifier.ImageFileProcessorQualified;
import org.jboss.weld.environment.se.Weld;
import org.jboss.weld.environment.se.WeldContainer;

public class ImageFileProcessorWeld {
    public static void main(String...args) {
        Weld weld = new Weld();
        WeldContainer container = weld.initialize();
 /*       ImageFileProcessor imageFileProcessor = container.select(ImageFileProcessor.class).get();
        System.out.println(imageFileProcessor.openFile("File1.png"));
        container.shutdown(); */
        System.out.println("Named!");
//        container = weld.initialize();
        ImageFileProcessorNamed imageFileProcessorNamed = container.select(ImageFileProcessorNamed.class).get();
        System.out.println(imageFileProcessorNamed.openFile("File1.jpg"));
        container.shutdown();
        container = weld.initialize();
        ImageFileProcessorQualified imageFileProcessorQualified = container.select(ImageFileProcessorQualified.class).get();
        System.out.println(imageFileProcessorQualified.openFile("File2.jpg"));
        container.shutdown();
    }
}
