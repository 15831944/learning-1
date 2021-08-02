package cdi_jbos.defaultWoNamed;

import cdi_jbos.interfaces.ImageFileEditor;

public class ImageFileProcessor {
    private ImageFileEditor imageFileEditor;

//Do not accept 2 things in the same time
//    @Inject
    public ImageFileProcessor(ImageFileEditor imageFileEditor) {
        this.imageFileEditor = imageFileEditor;
    }

    public String openFile(String fileName) {
        return imageFileEditor.openFile(fileName);
    }
}
