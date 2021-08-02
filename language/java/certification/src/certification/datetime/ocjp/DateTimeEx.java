package certification.datetime.ocjp;

import java.time.*;
import java.time.temporal.ChronoUnit;
import java.time.temporal.UnsupportedTemporalTypeException;

public class DateTimeEx {
    public static void main(String...args) {
        System.out.println(LocalDate.now());
        System.out.println(LocalTime.now());
        System.out.println(LocalDateTime.now());
        System.out.println(ZonedDateTime.now());

        LocalDate date1 = LocalDate.of(2015, Month.JANUARY, 20);
        LocalDate date2 = LocalDate.of(2015,1,20);
        System.out.println(date1.equals(date2));

        LocalTime time1 = LocalTime.of(6,15);//h:m
        LocalTime time2 = LocalTime.of(6,15,30);//h:m:s
        LocalTime time3 = LocalTime.of(6,15,30,200);//h:m:s:ns

        LocalDateTime dateTime1 = LocalDateTime.of(2015,Month.JANUARY,20,6,15,30);
        LocalDateTime dateTime2 = LocalDateTime.of(date1,time1);

        ZoneId zone = ZoneId.of("US/Eastern");
        ZonedDateTime zoned1 = ZonedDateTime.of(2015,1,20,6,15,30,200,zone);
        System.out.println(zoned1);

        ZoneId.getAvailableZoneIds().stream()
                .filter(z -> z.contains("US") || z.contains("America"))
                .sorted().limit(5).forEach(System.out::println);

        LocalDate date = LocalDate.of(2014,Month.JANUARY, 20);
        System.out.println(date); //2014-01-20
        date = date.plusDays(2);
        System.out.println(date); //2014-01-22
        date = date.plusWeeks(1);
        System.out.println(date); //2014-01-29
        date = date.plusMonths(1);
        System.out.println(date); //2014-02-28
        date = date.plusYears(5);
        System.out.println(date); //2019-02-28

        date = LocalDate.of(2020,Month.JANUARY, 20);
        LocalTime time = LocalTime.of(5,15);
        LocalDateTime dateTime = LocalDateTime.of(date, time);
        System.out.println(dateTime); //2020-01-20T05:15
        dateTime = dateTime.minusDays(1);
        System.out.println(dateTime); //2020-01-19T05:15
        dateTime = dateTime.minusHours(10);
        System.out.println(dateTime); //2020-01-18T19:15
        dateTime = dateTime.minusSeconds(30);
        System.out.println(dateTime); //2020-01-19T19:14:30

        dateTime = LocalDateTime.of(date, time).minusDays(1).minusHours(10).minusSeconds(30);
        System.out.println(dateTime);//2020-01-19T19:14:30

        LocalDate start = LocalDate.of(2015,Month.JANUARY, 1);
        LocalDate stop = LocalDate.of(2015,Month.MARCH, 30);
        performAnimalEnrichment(start,stop);
        Period period = Period.ofMonths(1);
        performAnimalEnrichment(start,stop, period);

        System.out.println(Period.of(1,2,3));

        durationExamples();
        chronoUnitExamples();
        instantsExamples();
        daylightsaving();
    }

    private static void daylightsaving() {
        LocalDate date = LocalDate.of(2016, Month.MARCH, 13);
        LocalTime time = LocalTime.of(1, 30);
        ZoneId zone = ZoneId.of("US/Eastern");
        ZonedDateTime dateTime = ZonedDateTime.of(date, time, zone);

        System.out.println(dateTime); // 2016–03–13T01:30–05:00[US/Eastern]

        dateTime = dateTime.plusHours(1);

        System.out.println(dateTime); // 2016–03–13T03:30–04:00[US/Eastern]

        date = LocalDate.of(2016, Month.NOVEMBER, 6);
        time = LocalTime.of(1, 30);
        zone = ZoneId.of("US/Eastern");
        dateTime = ZonedDateTime.of(date, time, zone);

        System.out.println(dateTime); // 2016–11–06T01:30–04:00[US/Eastern]

        dateTime = dateTime.plusHours(1);

        System.out.println(dateTime); // 2016–11–06T01:30–05:00[US/Eastern]

        dateTime = dateTime.plusHours(1);

        System.out.println(dateTime); // 2016–11–06T02:30–05:00[US/Eastern]

        date = LocalDate.of(2016, Month.MARCH, 13);
        time = LocalTime.of(2, 30);
        zone = ZoneId.of("US/Eastern");
        dateTime = ZonedDateTime.of(date, time, zone);
        System.out.println(dateTime);  // 2016–03–13T03:30–04:00[US/Eastern]
    }

    private static void instantsExamples() {
        Instant now = Instant.now();
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Instant later = Instant.now();
        Duration duration = Duration.between(now, later);
        System.out.println(duration.toMillis());

        Instant instant = ZonedDateTime.of(LocalDate.of(2015,1,10),
                LocalTime.of(10,15,30), ZoneId.of("US/Eastern")).toInstant();
        System.out.println(instant);        // 2015-01-10T15:15:30Z
        Instant nextDay = instant.plus(1, ChronoUnit.DAYS);
        System.out.println(nextDay); // 2015-01-11T15:15:30Z
        Instant nextHour = instant.plus(1, ChronoUnit.HOURS);
        System.out.println(nextHour); // 2015-01-10T16:15:30Z
        try {
            Instant nextWeek = instant.plus(1, ChronoUnit.WEEKS); // exception
        } catch(UnsupportedTemporalTypeException e) {
            System.out.println("Could not add weeks to instant");
        }
    }
    private static void chronoUnitExamples() {
        System.out.println("ChronoUnit examples");
        LocalTime one = LocalTime.of(5, 15);
        LocalTime two = LocalTime.of(6, 30);
        LocalDate date = LocalDate.of(2016, 1, 20);

        System.out.println(ChronoUnit.HOURS.between(one, two));   // 1
        System.out.println(ChronoUnit.MINUTES.between(one, two)); // 75
        try {
            System.out.println(ChronoUnit.MINUTES.between(one, date)); // DateTimeException
        } catch (DateTimeException e) {
            System.out.println("Mix Date and Time objects not permitted!!");
        }
    }
    private static void durationExamples() {
        System.out.println("Duration Examples");
        Duration daily = Duration.ofDays(1);
        Duration hourly = Duration.ofHours(1);
        Duration everyMinute = Duration.ofMinutes(1);
        Duration everyTenSeconds = Duration.ofSeconds(10);
        Duration everyMilli = Duration.ofMillis(1);
        Duration everyNano = Duration.ofNanos(1);
        System.out.println(daily);                // PT24H
        System.out.println(hourly);               // PT1H
        System.out.println(everyMinute);          // PT1M
        System.out.println(everyTenSeconds);      // PT10S
        System.out.println(everyMilli);           // PT0.001S
        System.out.println(everyNano);            // PT0.000000001S
        //similar
        daily = Duration.of(1, ChronoUnit.DAYS);
        hourly = Duration.of(1, ChronoUnit.HOURS);
        everyMinute = Duration.of(1, ChronoUnit.MINUTES);
        everyTenSeconds = Duration.of(10, ChronoUnit.SECONDS);
        everyMilli = Duration.of(1, ChronoUnit.MILLIS);
        everyNano = Duration.of(1, ChronoUnit.NANOS);

        LocalDate date = LocalDate.of(2015, 1, 20);
        LocalTime time = LocalTime.of(6, 15);
        LocalDateTime dateTime = LocalDateTime.of(date, time);
        Duration duration = Duration.ofHours(6);
        System.out.println(dateTime.plus(duration)); // 2015–01–20T12:1512:
        System.out.println(time.plus(duration));     // 12:1513:
        try {
            System.out.println(date.plus(duration));     // UnsupportedTemporalException
        } catch (UnsupportedTemporalTypeException e) {
            System.out.println("You could not add duration to a date !!");
        }
    }
    private static void performAnimalEnrichment(LocalDate start, LocalDate end, Period period) {
        LocalDate upTo = start;
        while(upTo.isBefore(end)) {
            System.out.println("Give new toy second time:" + upTo);
            upTo = upTo.plus(period);
        }
    }
    private static void performAnimalEnrichment(LocalDate start, LocalDate end) {
        LocalDate upTo = start;
        while (upTo.isBefore(end)) {
            System.out.println("Give new toy: " + upTo);
            upTo = upTo.plusMonths(1);
        }
    }
}
