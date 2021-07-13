package certification.datetime;
import java.text.SimpleDateFormat;
import java.time.*;
import java.time.format.*;
import java.util.Calendar;

public class WorkingDateTime {
	private static void dateNow() {
		LocalTime time = LocalTime.now();
		LocalDate date = LocalDate.now();
		LocalDateTime dateTime = LocalDateTime.now();
		System.out.println(dateTime + "=" + date + "T" + time);
		System.out.println("day of week = " + date.getDayOfWeek() + " from month " + date.getMonth());
	}

	private static void createDate() {
		LocalTime time = LocalTime.of(21, 24);
		LocalDate date = LocalDate.of(2016, Month.DECEMBER, 8);
		LocalDateTime dateTime = LocalDateTime.of(2016, Month.DECEMBER, 8, 21, 24);
		System.out.println(dateTime + "=" + date + "T" + time);
		dateTime = LocalDateTime.of(date, time);
		System.out.println(dateTime + "=" + date + "T" + time);
		dateTime = LocalDateTime.of(2016, 12, 8, 11, 22, 30);
		System.out.println(DateTimeFormatter.ofLocalizedTime(FormatStyle.SHORT).format(dateTime));
	}
	
	private static void formatDate() {
		DateTimeFormatter timeformater = DateTimeFormatter.ofPattern("HH:mm");
		DateTimeFormatter dateformater = DateTimeFormatter.ofPattern("yyyy-MM-dd");
		DateTimeFormatter datetimeformater = DateTimeFormatter.ofPattern("yyyy MMMM dd,HH mm");
		LocalDate date = LocalDate.parse("2016-12-08", dateformater);
		LocalTime time = LocalTime.parse("21:30", timeformater);
		LocalDateTime dateTime = LocalDateTime.parse("2016 decembrie 08,21 30", datetimeformater);
		System.out.println(dateTime + "=" + date + "T" + time);
		
		DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern("yyyy-MMMM-dd,HH:mm:ss");
		System.out.println(outputFormatter.format(dateTime));
		try {
			System.out.println(outputFormatter.format(date));
		} catch (Exception e) {
			System.out.println(e.getLocalizedMessage());
		}
		try {
			System.out.println(outputFormatter.format(time));
		} catch (Exception e) {
			System.out.println(e.getLocalizedMessage());
		}
	}

	private static void timeOperations() {
		LocalDate date = LocalDate.of(2016 , 12, 8);
		LocalTime time = LocalTime.of(21, 30);
		LocalDateTime dateTime = LocalDateTime.of(date, time);
		
		date = date.plusDays(2);
		dateTime = dateTime.plusDays(2);
		time = time.plusMinutes(100);
		dateTime = dateTime.plusMinutes(100);
		System.out.println(dateTime + "=" + date + "T" + time);
		dateTime = LocalDateTime.of(LocalDate.of(2016 , 12, 8), LocalTime.of(21, 30));
		Period period = Period.ofDays(2).ofYears(10);
		//equivalent with
		period = Period.ofYears(10);
		dateTime = dateTime.plus(period).plusMinutes(100);
		System.out.println(dateTime + "=" + date + "T" + time);
	}
	
	private static void localizedMethods() {
		LocalDate date = LocalDate.of(2016 , Month.DECEMBER, 8);
		LocalTime time = LocalTime.of(21, 30);
		LocalDateTime dateTime = LocalDateTime.of(date, time);
		DateTimeFormatter shortF = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.SHORT);
		DateTimeFormatter mediumF = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.MEDIUM);
		System.out.println(shortF.format(dateTime) + " vs " + mediumF.format(dateTime));
		shortF = DateTimeFormatter.ofLocalizedTime(FormatStyle.SHORT);
		mediumF = DateTimeFormatter.ofLocalizedTime(FormatStyle.MEDIUM);
		System.out.println(shortF.format(time) + " vs " + mediumF.format(time));
		try {
			System.out.println(shortF.format(date) + " vs " + mediumF.format(date));
		} catch (Exception e) {
			System.out.println(e.getLocalizedMessage());
		}
		shortF = DateTimeFormatter.ofLocalizedDate(FormatStyle.SHORT);
		mediumF = DateTimeFormatter.ofLocalizedDate(FormatStyle.MEDIUM);
		System.out.println(shortF.format(date) + " vs " + mediumF.format(date));
		try {
			System.out.println(shortF.format(time) + " vs " + mediumF.format(time));
		} catch (Exception e) {
			System.out.println(e.getLocalizedMessage());
		}
	}
	public static void millisecondsToDate() {
		long currentTime = System.currentTimeMillis();
		Calendar calendar = Calendar.getInstance();
		calendar.setTimeInMillis(currentTime);
		System.out.println(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss,SSS").format(calendar.getTime()));
	}
	public static void main(String[] args) {
		dateNow();
		createDate();
//		formatDate();
		timeOperations();
		localizedMethods();
		millisecondsToDate();
	}

}
