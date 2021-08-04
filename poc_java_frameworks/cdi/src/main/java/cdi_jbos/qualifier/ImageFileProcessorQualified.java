package cdi_jbos.qualifier;

import cdi_jbos.TimeLogger;
import cdi_jbos.interfaces.ImageFileEditor;
import cdi_jbos.interfaces.JpgFileEditorQualifier;

import javax.inject.Inject;
import javax.inject.Named;

public class ImageFileProcessorQualified {
    private ImageFileEditor imageFileEditor;
    private TimeLogger timeLogger;

    @Inject
    public ImageFileProcessorQualified(@JpgFileEditorQualifier ImageFileEditor imageFileEditor, TimeLogger timeLogger) {
        this.imageFileEditor = imageFileEditor;
        this.timeLogger = timeLogger;
    }

    public String openFile(String fileName) {
        return imageFileEditor.openFile(fileName) + " at: " + timeLogger.getTime();
    }
}
