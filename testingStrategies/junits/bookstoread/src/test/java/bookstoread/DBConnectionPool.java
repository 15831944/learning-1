package bookstoread;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;

abstract public class DBConnectionPool {
    @BeforeAll
    static void connectDBConnectionPool() {
        System.out.println("Initialize the DB connection pool");
    }

    @AfterAll
    static void closeDBConnectionPool() {
        System.out.println("Close the DB connection pool");
    }
}
