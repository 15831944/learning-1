package cdi_jbos.qualifier;

import cdi_jbos.interfaces.ImageFileEditor;
import cdi_jbos.interfaces.PngFileEditorQualifer;

@PngFileEditorQualifer
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
