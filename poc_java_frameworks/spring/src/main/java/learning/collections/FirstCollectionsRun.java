package learning.collections;

import learning.collections.beans.Library_Map;
import learning.collections.beans.Library_List;
import learning.collections.beans.Library_MapList;
import learning.collections.beans.Library_Set;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class FirstCollectionsRun {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("books.xml");
        Library_List booksList = (Library_List)context.getBean("library_list");
        booksList.displayBooks();
        Library_Set bookSet = (Library_Set)context.getBean("library_set");
        bookSet.display_books();
        Library_Map bookMap = (Library_Map)context.getBean("library_map");
        bookMap.display_books();
        Library_MapList bookMapList = (Library_MapList)context.getBean("library_maplist");
        bookMapList.display_books();
    }
}
