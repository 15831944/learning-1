package service;

import java.util.Base64;
import java.util.HashMap;
import java.util.Map;

/**
 * a simple ClassLoader used to load classes defined by bytecode. 
 * @author Gabriel Dimitriu
 *
 */
public class JavaClassLoaderSimple extends ClassLoader {
	
	private Map<String,Class<?>> types = new HashMap<String,Class<?>>();
	
	public JavaClassLoaderSimple(final ClassLoader classLoader) {
		super(classLoader);
	}
	
	@Override
	public Class<?> loadClass(final String name) throws ClassNotFoundException {
		if(name==null) {
			return null;
		}
		if(types.containsKey(name)){
			return types.get(name);
		}
		try {
			return findSystemClass(name);
		} catch (Exception e) {
		}
		return null;
	}
	
	public Class<?> loadClass(final String name, final String data) throws ClassNotFoundException {
		if (types.containsKey(name)) {
			return types.get(name);
		}
		byte[] buffer = Base64.getDecoder().decode(data);
		Class<?> type = defineClass(null, buffer, 0, buffer.length);
		types.put(name,type);
		return type;
	}
	
	public Class<?> loadClass(final String name, final byte[] buffer) throws ClassNotFoundException {
		if (types.containsKey(name)) {
			return types.get(name);
		}
		Class<?> type = defineClass(null, buffer, 0, buffer.length);
		types.put(name,type);
		return type;
	}
}
