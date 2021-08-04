package service;

import java.io.*;
import java.util.Base64;
import java.util.HashMap;
import java.util.Map;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;

public class JarLoading {
    private Map<String,String> classes = new HashMap<>();
    private String sourceJarName;

    public JarLoading(String jarName) {
        sourceJarName = jarName;
        readJarContents();
    }

    public String getByteCode(String className) {
        return classes.get(className);
    }
    private void readJarContents() {
        JarEntry entry = null;
        try (JarInputStream jin = new JarInputStream(new FileInputStream(sourceJarName))){
            entry = jin.getNextJarEntry();
            while(entry != null) {
                if (!entry.isDirectory()) {
                    String name = entry.getName();
                    if (name.endsWith(".class")) {
                        name = name.replace(File.separator, ".");
                        byte[] buffer = new byte[2048];
                        int count =  jin.read(buffer);
                        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
                        StringBuilder builder = new StringBuilder();
                        while (count != -1) {
                            outputStream.write(buffer, 0, count);
                            for (int i = 0 ; i < buffer.length; i++)
                                buffer[i] = 0;
                            count = jin.read(buffer);
                        }
                        outputStream.close();
                        classes.put(name, Base64.getEncoder().encodeToString(outputStream.toByteArray()));
                    }
                }
                entry = jin.getNextJarEntry();
            }
        } catch (IOException e) {
            System.out.println("Could not read the last jar with error " + e.getMessage());
        }
    }
}
