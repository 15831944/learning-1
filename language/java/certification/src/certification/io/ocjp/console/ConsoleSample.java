package certification.io.ocjp.console;

import java.io.Console;

public class ConsoleSample {
    public static void main(String...args) {
        Console console = System.console();
        if (console != null) {
            String userInput = console.readLine();
            System.out.println("You have entered: " + userInput);
            console.writer().println("Welcome to Our Zoo!");
            console.format("Our zoo has 391 animals and employs 25 people.");
            console.writer().println();
            console.printf("The zoo spans 128.91 acres.");
        } else {
            throw new RuntimeException("Console not available");
        }
    }
}
