package cdi_jbos.named;

import cdi_jbos.interfaces.ImageFileEditor;

import javax.inject.Named;

@Named("PngFileEditor")
public class PngFileEditor implements ImageFileEditor {

    public String openFile(String fileName) {
        return "Opening png file " + fileName;
    }

    public String editFile(String fileName) {
        return "Editing png file " + fileName;
    }

    public String writeFile(String fileNane) {
        return "Writing png file " + fileNane;
    }

    public String saveFile(String fileName) {
        return "Saving png file " + fileName;
    }
}
