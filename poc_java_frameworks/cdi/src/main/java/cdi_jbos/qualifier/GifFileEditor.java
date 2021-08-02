package cdi_jbos.qualifier;

import cdi_jbos.interfaces.GifFileEditorQualifier;
import cdi_jbos.interfaces.ImageFileEditor;

@GifFileEditorQualifier
public class GifFileEditor implements ImageFileEditor {

    public String openFile(String fileName) {
        return "Opening GIF file " + fileName;
    }

    public String editFile(String fileName) {
        return "Editing GifFile file " + fileName;
    }

    public String writeFile(String fileNane) {
        return "Writing GIF file " + fileNane;
    }

    public String saveFile(String fileName) {
        return "Save GIF file " + fileName;
    }
}
