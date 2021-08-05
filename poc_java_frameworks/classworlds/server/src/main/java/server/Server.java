package server;

import org.codehaus.plexus.classworlds.ClassWorld;
import org.codehaus.plexus.classworlds.launcher.Launcher;
import org.codehaus.plexus.classworlds.realm.ClassRealm;
import org.codehaus.plexus.classworlds.realm.NoSuchRealmException;

import java.io.InputStream;
import java.net.URL;

public class Server {
    private final ClassWorld world;
    private OperationsWithExternalLauncher opWithExternal;
    private Operations op;

    public Server(ClassWorld world) {
        this.world = world;
        ClassLoader orig = Thread.currentThread().getContextClassLoader();
        ClassRealm realm = null;
        try {
            realm = world.getRealm("app.real");
        } catch (NoSuchRealmException e) {
            e.printStackTrace();
            return;
        }
        Thread.currentThread().setContextClassLoader(realm);
        opWithExternal = new OperationsWithExternalLauncher(world);
        op = new Operations();
        Thread.currentThread().setContextClassLoader(orig);
    }
    public Server() {
        world = null;
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
        try {
            CustomClassLoader classLoader = new CustomClassLoader(realm);
            classLoader.addClassLoader(orig);
            Thread.currentThread().setContextClassLoader(classLoader);
            /* this is not needed
            Class<?> cls = classLoader.loadClass("server.Operations");
            Object obj = cls.getDeclaredConstructor().newInstance();
            op = (Operations) obj;
            Method method =obj.getClass().getMethod("runAll");
            method.invoke(obj);
             */
            op = new Operations();
        } catch (Throwable e) {
            e.printStackTrace();
        }
        Thread.currentThread().setContextClassLoader(orig);
    }

    public static void main(String...args) {
        Server server = new Server();
        server.runOperations();
    }

    public static void main(String[] args, ClassWorld world) {
        Server server = new Server(world);
        server.runWithExternal();
    }
    public void runWithExternal() {
        opWithExternal.runAll();
        op.testRealm();
    }

    public void runOperations() {
        op.runAll();
    }

}
