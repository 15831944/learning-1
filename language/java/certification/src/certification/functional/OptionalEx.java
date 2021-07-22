package functional;

import java.util.NoSuchElementException;
import java.util.Optional;

public class OptionalEx {
    public static Optional<Double> average(int... scores) {
        if (scores.length == 0) {
            return Optional.empty();
        }
        int sum = 0;
        for(int score: scores)
            sum += score;
        Double value = Double.valueOf(sum/scores.length);
        return (value == null) ? Optional.empty() : Optional.of(value);
//        return Optional.of((double) sum/scores.length);
    }
    public static void main(String...args) {
        System.out.println(OptionalEx.average(90,100));//Optional[95.0]
        System.out.println(OptionalEx.average()); //Optional.empty
//        Optional<Double> opt = OptionalEx.average();
//        try {
//            System.out.println(opt.get());
//        } catch (NoSuchElementException e) {
//            e.printStackTrace();
//        }
        Optional<Double> opt = OptionalEx.average(90, 100);
        if (opt.isPresent())
             System.out.println(opt.get()); // 95.0
        opt.ifPresent(System.out::println);
        Optional<Double> opt1 = OptionalEx.average();
        System.out.println(opt1.orElse(Double.NaN));
        System.out.println(opt1.orElseGet(() -> Math.random()));
        try {
            System.out.println(opt1.orElseThrow(() -> new IllegalStateException()));
        } catch (IllegalStateException e) {
            System.out.println("Catch exception thrown by optional");
            e.printStackTrace();
        }
    }
}
