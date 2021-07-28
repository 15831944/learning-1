package ocjpetc;

import java.util.Locale;
import java.util.Properties;
import java.util.ResourceBundle;
import java.util.Set;

public class LocatizatonEx {
    public static void main(String...args) {
        locale();
        resourceBundle();
    }

    private static void resourceBundle() {
        Locale defaultLocale = Locale.getDefault();
        Locale locale = new Locale("en","US");
        ResourceBundle rb = ResourceBundle.getBundle("localization", locale);
        System.out.println(rb.getString("hello"));
        System.out.println(rb.getString("open"));
        locale = new Locale("fr","FR");
        ResourceBundle rbfr = ResourceBundle.getBundle("localization", locale);
        System.out.println(rbfr.getString("hello"));
        System.out.println(rbfr.getString("open"));
        Set<String> keys = rb.keySet();
        keys.stream().map(k -> k + "=" + rb.getString(k)).forEach(System.out::println);
        System.out.println("With properties");
        Properties props = new Properties();
        rb.keySet().stream().forEach(k -> props.put(k,rb.getString(k)));
        for( String str : props.stringPropertyNames()) {
            System.out.println(str + "=" + props.getProperty(str));
        }
        System.out.println("Still takes the english not french");
        Locale.setDefault(locale);
        Properties propsfr = new Properties();
        rb.keySet().stream().forEach(k -> propsfr.put(k,rb.getString(k)));
        for( String str : propsfr.stringPropertyNames()) {
            System.out.println(str + "=" + propsfr.getProperty(str));
        }
        Locale.setDefault(defaultLocale);
    }
    private static void locale() {
        Locale locale = Locale.getDefault();
        System.out.println(locale);
        System.out.println(Locale.GERMAN);  // de
        System.out.println(Locale.GERMANY); // de_DE
        System.out.println(new Locale("fr"));            // fr
        System.out.println(new Locale("hi", "IN"));      // hi_IN
        Locale l1 = new Locale.Builder()
                .setLanguage("en")
                .setRegion("US")
                .build();
        Locale l2 = new Locale.Builder()
                .setRegion("US")
                .setLanguage("en")
                .build();
        System.out.println(l1); //en_US
        System.out.println(l2); //en_US
        l2 = new Locale.Builder()  // bad but legal
                .setRegion("us")
                .setLanguage("EN")
                .build();
        System.out.println(l2);//en_US
        System.out.println("Changing locale");
        l1 = Locale.getDefault();
        l2 = new Locale.Builder()
                .setRegion("RO")
                .setLanguage("ro").build();
        System.out.println(l2);//ro_RO
        Locale.setDefault(l2);
        System.out.println(Locale.getDefault());//ro_RO
        Locale.setDefault(l1);
        System.out.println(Locale.getDefault());//en_US
    }
}
