package cdi_jbos.named;

import cdi_jbos.TimeLogger;
import cdi_jbos.interfaces.ImageFileEditor;

import javax.inject.Inject;
import javax.inject.Named;

public class ImageFileProcessorNamed {
    private ImageFileEditor imageFileEditor;
    private TimeLogger timeLogger;

    @Inject
    public ImageFileProcessorNamed(@Named("JpgFileEditor") ImageFileEditor imageFileEditor, TimeLogger timeLogger) {
        this.imageFileEditor = imageFileEditor;
        this.timeLogger = timeLogger;
    }

    public String openFile(String fileName) {
        return imageFileEditor.openFile(fileName) + " at: " + timeLogger.getTime();
    }
}
