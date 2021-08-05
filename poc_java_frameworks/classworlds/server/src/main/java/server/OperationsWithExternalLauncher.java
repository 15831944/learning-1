package server;

import org.codehaus.plexus.classworlds.ClassWorld;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;
import service.IService;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Scanner;

public class OperationsWithExternalLauncher {
    private final ClassWorld world;
    public OperationsWithExternalLauncher(ClassWorld world) {
        this.world = world;
    }

    public void runAll() {
        usingJarLoading();
        System.out.println("Replace the client with original one");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("c")) {
            in.nextLine();
        }
        notWorkingAsExpected();
    }

    public void usingJarLoading() {
        System.out.println("usingJarLoading");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        CustomClassLoader classLoader = new CustomClassLoader();
        ClassRealm realm = null;
        try {
            realm = world.getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realm);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        JarLoading jar = new JarLoading("./ext/client.jar");
        String classStr = jar.getByteCode("client.ClientEx1.class");
        Class<?> loaded = null;
        try {
            if (classStr != null) {
                loaded = classLoader.loadClass("server.IService");
                loaded = classLoader.loadClass("client.ClientEx1", classStr);
                if (loaded != null) {
                    IService service = (IService) loaded.getConstructor().newInstance();
                    if (service != null)
                        service.printme();
                }
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }

        System.out.println("Replace the client");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("c")) {
            in.nextLine();
        }
        classLoader = new CustomClassLoader();
        classLoader.addClassLoader(realm);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        jar = new JarLoading("./ext/client.jar");
        try {
            classStr = jar.getByteCode("client.ClientEx1.class");
            if (classStr != null) {
                loaded = classLoader.loadClass("client.ClientEx1", classStr);
                if (loaded != null) {
                    IService service = (IService) loaded.getConstructor().newInstance();
                    if (service != null)
                        service.printme();
                }
            }
            classStr = jar.getByteCode("client.ClientEx2.class");
            if (classStr != null) {
                loaded = classLoader.loadClass("client.ClientEx2", classStr);
                if (loaded != null) {
                    IService service = (IService) loaded.getConstructor().newInstance();
                    if (service != null)
                        service.printme();
                }
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        Thread.currentThread().setContextClassLoader(orig);
    }

    public void notWorkingAsExpected() {
        System.out.println("notWorkingAsExpected");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        ClassRealm realm = null;
        try {
            realm = world.getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        CustomClassLoader classLoader = new CustomClassLoader(realm);
        File file = new File("./ext/client.jar");
        URL url = null;
        try {
            url = file.toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }
        URL[] urls = new URL[]{url};
        ClassLoader cl = new URLClassLoader(urls, realm);
        classLoader.addClassLoader(cl);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> loaded = classLoader.loadClass("client.ClientEx1");
            if (loaded != null) {
                IService service = (IService) loaded.getConstructor().newInstance();
                service.printme();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        System.out.println("Replace the client");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("c")) {
            in.nextLine();
        }
        file = new File("./ext/client.jar");
        url = null;
        try {
            url = file.toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }
        urls = new URL[]{url};
        cl = new URLClassLoader(urls, realm);
        classLoader = new CustomClassLoader(realm);
        classLoader.addClassLoader(cl);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> loaded = classLoader.loadClass("client.ClientEx1");
            if (loaded != null) {
                IService service = (IService) loaded.getConstructor().newInstance();
                service.printme();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        try {
            Class<?> loaded = classLoader.loadClass("client.ClientEx2");
            if (loaded != null) {
                IService service = (IService) loaded.getConstructor().newInstance();
                service.printme();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        Thread.currentThread().setContextClassLoader(orig);
    }
}
