package junits;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;

import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.function.BiFunction;
import java.util.function.Function;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertNull;

public class JuniTests {

    private JuniTests(TestInfo testInfo) {
        System.out.println("Working on test " + testInfo.getDisplayName());
    }

    @Test
    @DisplayName("null assertion test")
    protected  void nullAssertionTest(TestInfo testInfo) {
        String str = null;
        assertNull(str);
        assertNull(str, "str should be null");
        assertNull(str, () -> "str should be null");
    }

    @Test
    @DisplayName("Check for Even Number")
    protected void shouldCheckForEvenNumbers(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        int number = new Random(10).nextInt();
        assertTrue(() -> number%2 ==0, number+ " is not an even number");
        BiFunction<Integer, Integer, Boolean> divisible = (x, y) -> x%y == 0;
        Function<Integer, Boolean> multipleOf2 = (x) -> divisible.apply(x,2);
        assertTrue(() -> multipleOf2.apply(number),() -> " 2 is not factor of number " + number);
        List<Integer> numbers = Arrays.asList(1,1,1,1,2);
        assertTrue( () -> numbers.stream().distinct().anyMatch(JuniTests::isEven),
                "Did not find an even number");
    }
    static boolean isEven(int number) {
        return number %2 == 0;
    }

    @Test
    @DisplayName("String is not empty")
    protected void stringIsNotEmpty(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        String str = "";
        assertFalse(str.isEmpty());
    }

    @Test
    @DisplayName("Throw exception in method")
    protected  void thisMethodThrowsException(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        String str = null;
        assertTrue(str.isEmpty());
    }
}
