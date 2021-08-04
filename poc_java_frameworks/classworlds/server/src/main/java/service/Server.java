package service;

import org.codehaus.plexus.classworlds.ClassWorld;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;

import java.io.File;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Scanner;

public class Server {
    private final ClassWorld world;

    public Server(ClassWorld world) {
        this.world = world;
    }

    public static void main(String[] args, ClassWorld world) {
        Server server = new Server(world);
        server.notWorkingAsExpected();
        server.usingJarLoading();
    }

    public void usingJarLoading() {
        ClassRealm realm = null;
        try {
            realm = world.getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        CustomClassLoader classLoader = new CustomClassLoader(realm);
        classLoader.addClassLoader(Thread.currentThread().getContextClassLoader());
        Thread.currentThread().setContextClassLoader(classLoader);
        JarLoading jar = new JarLoading("./ext/client.jar");
        String classStr = jar.getByteCode("client.ClientEx1.class");
        Class<?> loaded = null;
        try {
            if (classStr != null) {
                loaded = classLoader.loadClass("service.IService");
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
        /*
        System.out.println("Replace the client");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("c")) {
            in.nextLine();
        }
        */
        jar = new JarLoading("./ext/client.jar");
        classStr = jar.getByteCode("client.ClientEx2.class");
        try {
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
    }

    public void notWorkingAsExpected() {
        ClassRealm realm = null;
        try {
            realm = world.getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        CustomClassLoader classLoader = new CustomClassLoader(realm);
        /* wrong class loader  this will not work */
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
        classLoader.addClassLoader(Thread.currentThread().getContextClassLoader());
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
    }
}
