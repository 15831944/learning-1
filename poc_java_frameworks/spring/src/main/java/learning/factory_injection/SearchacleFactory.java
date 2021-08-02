package learning.factory_injection;

public class SearchacleFactory {
    private static SearchacleFactory searchacleFactory;
    public static SearchacleFactory getSearchacleFactory() {
        if(searchacleFactory == null) {
            searchacleFactory = new SearchacleFactory();
        }
        System.out.println("Factory method is used : getSearchacleFactory()");
        return searchacleFactory;
    }
}
