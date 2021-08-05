package server;

import org.codehaus.plexus.classworlds.launcher.Launcher;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;
import service.IService;

import java.io.File;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Scanner;

public class Operations {

    public void runAll() {
        usingJarLoadingRealm();
        notWorkingAsExpectedRealm();
        testRealm();
    }

    public void usingJarLoadingRealm() {
        System.out.println("usingJarLoadingRealm");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        CustomClassLoader classLoader = new CustomClassLoader();
        ClassRealm realm = null;
        ClassLoader cl = Thread.currentThread().getContextClassLoader();
        URL url = cl.getResource ("classworlds.conf");

        Launcher launcher = new Launcher();

        try {
            InputStream is = url.openStream();
            launcher.configure(is);
        } catch (Throwable e) {
            e.printStackTrace();
            return;
        }

        try {
            realm = launcher.getWorld().getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realm);
        try {
            realm = launcher.getWorld().getRealm("app");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realm);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        JarLoading jar = new JarLoading("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
        String classStr = jar.getByteCode("client.ClientEx1.class");
        Class<?> loaded = null;
        try {
            if (classStr != null) {
                loaded = classLoader.loadClass("service.TestService");
                if (loaded != null) {
                    IService service = (IService) loaded.getConstructor().newInstance();
                    if (service != null)
                        service.printme();
                }
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

        jar = new JarLoading("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
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
    public void notWorkingAsExpectedRealm() {
        System.out.println("notWorkingAsExpectedRealm");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        URL url = orig.getResource ("classworlds.conf");
        ClassRealm realm = null;
        Launcher launcher = new Launcher();

        try {
            InputStream is = url.openStream();
            launcher.configure(is);
        } catch (Throwable e) {
            e.printStackTrace();
            return;
        }

        try {
            realm = launcher.getWorld().getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        CustomClassLoader classLoader = new CustomClassLoader(realm);
        try {
            realm = launcher.getWorld().getRealm("app");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realm);
        /* wrong class loader  this will not work */
        File file = new File("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
        try {
            url = file.toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }
        URL[] urls = new URL[]{url};
        ClassLoader clJar = new URLClassLoader(urls, realm);
        classLoader.addClassLoader(clJar);
        classLoader.addClassLoader(orig);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> loaded = classLoader.loadClass("service.TestService");
            if (loaded != null) {
                IService service = (IService) loaded.getConstructor().newInstance();
                if (service != null)
                    service.printme();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
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
    public void testRealm() {
        System.out.println("testRealm");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        URL url = orig.getResource ("classworlds.conf");
        ClassRealm realm = null;
        Launcher launcher = new Launcher();

        try {
            InputStream is = url.openStream();
            launcher.configure(is);
        } catch (Throwable e) {
            e.printStackTrace();
            return;
        }

        try {
            realm = launcher.getWorld().getRealm("app");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        Thread.currentThread().setContextClassLoader(realm);
        try {
            Class<?> loaded = realm.loadClass("service.TestService");
            if (loaded != null) {
                IService service = (IService) loaded.getConstructor().newInstance();
                if (service != null)
                    service.printme();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        Thread.currentThread().setContextClassLoader(orig);
    }
}
