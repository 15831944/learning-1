package service;

import java.util.*;

public class CustomClassLoader extends ClassLoader {

	private Map<String,Class<?>> types = new HashMap<String,Class<?>>();

	private List<ClassLoader> classLoaders = new ArrayList<>();
	/**
	 * 
	 */
	public CustomClassLoader() {
		//nothing to do here
	}

	/**
	 * @param parent
	 */
	public CustomClassLoader(ClassLoader parent) {
		super(parent);
		//nothing to do here
	}
	
	
	/**
	 * @param classLoader the classloader to be added.
	 */
	public void addClassLoader(final ClassLoader classLoader) {
		classLoaders.add(classLoader);
	}

	/* (non-Javadoc)
	 * @see java.lang.ClassLoader#loadClass(java.lang.String)
	 */
	@Override
	public Class<?> loadClass(final String name) throws ClassNotFoundException {
		if(name==null) {
			return null;
		}
		if(types.containsKey(name)){
			return types.get(name);
		}
		//load the class from parent classloader
		try {
			return getClass().getClassLoader().loadClass(name);
		} catch (ClassNotFoundException e) {
			//nothing to do
		}
		for (ClassLoader classLoader : classLoaders) {
			try {
				return classLoader.loadClass(name);
			} catch (ClassNotFoundException e) {
				//nothing to do get the next classloader
			}
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
		Class<?> type = super.defineClass(name, buffer, 0, buffer.length);
		types.put(name,type);
		return type;
	}
}
