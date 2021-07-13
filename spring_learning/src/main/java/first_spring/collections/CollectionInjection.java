package first_spring.collections;

import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

import org.springframework.context.support.GenericXmlApplicationContext;

public class CollectionInjection {

	private Map<String, Object> myMap;
	private List<Object> myList;
	private Set<Object> mySet;
	private Properties myProp;
	
	public static void main(String[] args) {
		GenericXmlApplicationContext loader = new GenericXmlApplicationContext();
		loader.load("Collections.xml");
		loader.refresh();

		CollectionInjection injected = (CollectionInjection) loader.getBean("collectionInjection");
		injected.display();
	}

	public List<Object> getMyList() {
		return myList;
	}

	public void setMyList(List<Object> myList) {
		this.myList = myList;
	}

	public Map<String, Object> getMyMap() {
		return myMap;
	}

	public void setMyMap(Map<String, Object> myMap) {
		this.myMap = myMap;
	}

	public Set<Object> getMySet() {
		return mySet;
	}

	public void setMySet(Set<Object> mySet) {
		this.mySet = mySet;
	}

	public Properties getMyProp() {
		return myProp;
	}

	public void setMyProp(Properties myProp) {
		this.myProp = myProp;
	}

	public void display() {
		System.out.println("displaying map contents");
		for (Map.Entry<String, Object> entry : myMap.entrySet()) {
			System.out.println("key= " + entry.getKey() + "- value = " + entry.getValue());
		}
		System.out.println("displaying properties contents");
		for (Map.Entry<Object, Object> prop : myProp.entrySet()) {
			System.out.println("key= " + prop.getKey() + "- value = " + prop.getValue());
		}
		System.out.println("displaying list contents");
		for (Object obj : myList) {
			System.out.println("Value = " + obj);
		}
		System.out.println("displaying set contents");
		for (Object obj : mySet) {
			System.out.println("Value = " + obj);
		}
	}
}
