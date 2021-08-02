package cdi_jbos.interfaces;

public interface ImageFileEditor {
    String openFile(String fileName);
    String editFile(String fileName);
    String writeFile(String fileNane);
    String saveFile(String fileName);
}
