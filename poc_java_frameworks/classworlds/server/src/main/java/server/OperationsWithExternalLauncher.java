package server;

import org.codehaus.plexus.classworlds.ClassWorld;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;
import service.IService;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;

public class OperationsWithExternalLauncher {
    private final ClassWorld world;
    public OperationsWithExternalLauncher(ClassWorld world) {
        this.world = world;
    }

    public void runAll() {
        usingJarLoading();
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
        Thread.currentThread().setContextClassLoader(orig);
    }
}
