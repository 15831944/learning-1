package cdi_jbos.qualifier;

import cdi_jbos.interfaces.ImageFileEditor;
import cdi_jbos.interfaces.JpgFileEditorQualifier;

@JpgFileEditorQualifier
public class JpgFileEditor implements ImageFileEditor {

    public String openFile(String fileName) {
        return "Opening jpeg file " + fileName;
    }

    public String editFile(String fileName) {
        return "Editing jpg file " + fileName;
    }

    public String writeFile(String fileNane) {
        return "Writing jpg file " + fileNane;
    }

    public String saveFile(String fileName) {
        return "Saving jpg file " + fileName;
    }
}
