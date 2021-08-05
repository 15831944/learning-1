package server;

import org.codehaus.plexus.classworlds.launcher.Launcher;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;

import java.io.File;
import java.io.InputStream;
import java.lang.reflect.Method;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Arrays;
import java.util.Scanner;

public class Operations {

    public void runAll() {
        usingJarLoadingRealm();
        System.out.println("Replace the client with original one");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        while(!str.equals("c")) {
            in.nextLine();
        }
        notWorkingAsExpectedRealm();
        testRealm();
    }

    public void usingJarLoadingRealm() {
        System.out.println("usingJarLoadingRealm");
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        CustomClassLoader classLoader = new CustomClassLoader();
        ClassRealm realm = null;
        ClassRealm realmReal = null;
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
            realmReal = launcher.getWorld().getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realmReal);
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
                    Object service = loaded.getConstructor().newInstance();
                    if (service != null) {
                        Method method =service.getClass().getMethod("printme");
                        method.invoke(service);
                    }
                }
                loaded = classLoader.loadClass("client.ClientEx1", classStr);
                if (loaded != null) {
                    Object service = loaded.getConstructor().newInstance();
                    if (service != null) {
                        Method method =service.getClass().getMethod("printme");
                        method.invoke(service);
                    }
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
        classLoader.addClassLoader(realmReal);
        jar = new JarLoading("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
        try {
            classStr = jar.getByteCode("client.ClientEx1.class");
            if (classStr != null) {
                loaded = classLoader.loadClass("client.ClientEx1", classStr);
                if (loaded != null) {
                    Object service = loaded.getConstructor().newInstance();
                    if (service != null) {
                        Method method =service.getClass().getMethod("printme");
                        method.invoke(service);
                    }
                }
            }

            classStr = jar.getByteCode("client.ClientEx2.class");
            if (classStr != null) {
                loaded = classLoader.loadClass("client.ClientEx2", classStr);
                if (loaded != null) {
                    Object service = loaded.getConstructor().newInstance();
                    if (service != null) {
                        Method method =service.getClass().getMethod("printme");
                        method.invoke(service);
                    }
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
        ClassRealm realmReal = null;
        Launcher launcher = new Launcher();

        try {
            InputStream is = url.openStream();
            launcher.configure(is);
        } catch (Throwable e) {
            e.printStackTrace();
            return;
        }

        try {
            realmReal = launcher.getWorld().getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        CustomClassLoader classLoader = new CustomClassLoader();
        classLoader.addClassLoader(realmReal);

        /* wrong class loader  this will not work */
        File file = new File("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
        try {
            url = file.toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }
        URL[] urls = new URL[]{url};
        ClassLoader clJar = new URLClassLoader(urls, realmReal);
        classLoader.addClassLoader(clJar);
        classLoader.addClassLoader(orig);
        try {
            realm = launcher.getWorld().getRealm("app");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        classLoader.addClassLoader(realm);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> loaded = classLoader.loadClass("service.TestService");
            if (loaded != null) {
                Object service = loaded.getConstructor().newInstance();
                if (service != null) {
                    Method method =service.getClass().getMethod("printme");
                    method.invoke(service);
                }
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        try {
            Class<?> loaded = classLoader.loadClass("client.ClientEx1");
            if (loaded != null) {
                Object service = loaded.getConstructor().newInstance();
                if (service != null) {
                    Method method =service.getClass().getMethod("printme");
                    method.invoke(service);
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
        classLoader.addClassLoader(realmReal);

        file = new File("/home/gaby/public-git/learning/poc_java_frameworks/classworlds/server/target/ext/client.jar");
        try {
            url = file.toURI().toURL();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }
        urls = new URL[]{url};
        clJar = new URLClassLoader(urls, realmReal);
        classLoader.addClassLoader(clJar);
        classLoader.addClassLoader(orig);
        classLoader.addClassLoader(realm);
        Thread.currentThread().setContextClassLoader(classLoader);
        try {
            Class<?> loaded = classLoader.loadClass("client.ClientEx1");
            if (loaded != null) {
                Object service = loaded.getConstructor().newInstance();
                if (service != null) {
                    Method method =service.getClass().getMethod("printme");
                    method.invoke(service);
                }
            }
            loaded = classLoader.loadClass("client.ClientEx2");
            if (loaded != null) {
                Object service = loaded.getConstructor().newInstance();
                if (service != null) {
                    Method method =service.getClass().getMethod("printme");
                    method.invoke(service);
                }
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
                Object service = loaded.getConstructor().newInstance();
                if (service != null) {
                    Method method =service.getClass().getMethod("printme");
                    method.invoke(service);
                }
            }
        } catch (Throwable e) {
            e.printStackTrace();
            Arrays.stream(realm.getURLs()).forEach(System.out::println);
        }
        Thread.currentThread().setContextClassLoader(orig);
    }
}
