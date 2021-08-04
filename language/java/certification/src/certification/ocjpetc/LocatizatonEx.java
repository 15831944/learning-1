package certification.ocjpetc;

import java.text.NumberFormat;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.Month;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.time.temporal.UnsupportedTemporalTypeException;
import java.util.Locale;
import java.util.Properties;
import java.util.ResourceBundle;
import java.util.Set;

public class LocatizatonEx {
    public static void main(String...args) {
        locale();
        resourceBundle();
        formattingNumbers();
        formattingDatesTimes();
    }

    private static void formattingDatesTimes() {
        LocalDate date = LocalDate.of(2020, Month.JANUARY, 20);
        System.out.println(date.getDayOfWeek());     // MONDAY
        System.out.println(date.getMonth());          // JANUARY
        System.out.println(date.getYear());          // 2020
        System.out.println(date.getDayOfYear());     // 20
        LocalTime time = LocalTime.of(11, 12, 34);
        LocalDateTime dateTime = LocalDateTime.of(date, time);
        System.out.println(date.format(DateTimeFormatter.ISO_LOCAL_DATE));
        System.out.println(time.format(DateTimeFormatter.ISO_LOCAL_TIME));
        System.out.println(dateTime.format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        DateTimeFormatter shortDateTime = DateTimeFormatter.ofLocalizedDate(FormatStyle.SHORT);
        System.out.println(shortDateTime.format(dateTime));     // 1/20/20
        System.out.println(shortDateTime.format(date));         // 1/20/20
        try {
            System.out.println(shortDateTime.format(time)); // UnsupportedTemporalTypeException
        } catch (UnsupportedTemporalTypeException e) {
            System.out.println(e.getLocalizedMessage() + " " + time  + " using shortDateTime");
        }
        System.out.println(dateTime.format(shortDateTime));
        System.out.println(date.format(shortDateTime));
        try {
            System.out.println(time.format(shortDateTime));
        } catch (UnsupportedTemporalTypeException e) {
            System.out.println(e.getLocalizedMessage() + " " + shortDateTime + " using time");
        }

        date = LocalDate.of(2020, Month.JANUARY, 20);
        time = LocalTime.of(11, 12, 34);
        dateTime = LocalDateTime.of(date, time);

        DateTimeFormatter shortF = DateTimeFormatter
                .ofLocalizedDateTime(FormatStyle.SHORT);
        DateTimeFormatter mediumF = DateTimeFormatter
                .ofLocalizedDateTime(FormatStyle.MEDIUM);
        System.out.println(shortF.format(dateTime));      // 1/20/20 11:12 AM
        System.out.println(mediumF.format(dateTime));     // Jan 20, 2020 11:12:34 AM

        DateTimeFormatter f = DateTimeFormatter.ofPattern("MMMM dd, yyyy, hh:mm");
        System.out.println(dateTime.format(f));     // January 20, 2020, 11:12

        f = DateTimeFormatter.ofPattern("MM dd yyyy");
        date = LocalDate.parse("01 02 2015", f);
        time = LocalTime.parse("11:22");
        System.out.println(date);          // 2015–01–02
        System.out.println(time);          // 11:22
    }

    private static void formattingNumbers() {
        int attendeesPerYear = 3_200_000;
        int attendeesPerMonth = attendeesPerYear/12;
        NumberFormat us = NumberFormat.getInstance(Locale.US);
        System.out.println(us.format(attendeesPerMonth));
        NumberFormat de = NumberFormat.getInstance(Locale.GERMANY);
        System.out.println(de.format(attendeesPerMonth));
        NumberFormat ca = NumberFormat.getInstance(Locale.CANADA_FRENCH);
        System.out.println(ca.format(attendeesPerMonth));
        double price = 48;
        us = NumberFormat.getCurrencyInstance(Locale.US);
        System.out.println(us.format(price));
        us = NumberFormat.getInstance(Locale.US);
        NumberFormat fr = NumberFormat.getInstance(Locale.FRANCE);
        String discount = "40.45";
        try {
            System.out.println(us.parse(discount)); //40.45
        } catch (ParseException e) {
            e.printStackTrace();
        }
        try {
            System.out.println(fr.parse(discount)); //40
        } catch (ParseException e) {
            e.printStackTrace();
        }
        NumberFormat nf = NumberFormat.getInstance();
        String one = "456abc";
        String two = "-2.5165x10";
        String three = "x85.3";
        try {
            System.out.println(nf.parse(one));  // 456
        } catch (ParseException e) {
            e.printStackTrace();
        }
        try {
            System.out.println(nf.parse(two));  // -2.5165
        } catch (ParseException e) {
            e.printStackTrace();
        }
        try {
            System.out.println(nf.parse(three));// throws ParseException
        } catch (ParseException e) {
            e.printStackTrace();
        }
        String amt = "$92,807.99";
        NumberFormat cf = NumberFormat.getCurrencyInstance();
        try {
            double value = (Double) cf.parse(amt);
            System.out.println(value); // 92807.99
        } catch (ParseException e) {
            e.printStackTrace();
        }

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
        locale = new Locale("en","CA");
        ResourceBundle rbCA = ResourceBundle.getBundle("localization", locale);
        System.out.print(rbCA.getString("hello"));
        System.out.print(". ");
        System.out.print(rbCA.getString("name"));
        System.out.print(" ");
        System.out.print(rbCA.getString("open"));
        System.out.print(" ");
        System.out.println(rbCA.getString("visitor"));
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
