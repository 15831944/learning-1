package genericscollections.generics;

import java.util.ArrayList;
import java.util.List;

public class UnboundWildcard {
    public static void printList(List<Object> list) {
        for (Object x: list) System.out.println(x);
    }
    public static void printList1(List<?> list) {
        for (Object x: list)  System.out.println(x);
    }
    public static void main(String[] args) {
        List<String> keywords = new ArrayList<>();
        keywords.add("java");
        printList1(keywords);
//        printList(keywords);    // DOES NOT COMPILE
    }
}
