package guice_learning.basic_injection.test;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import com.google.inject.AbstractModule;
import com.google.inject.Guice;
import com.google.inject.Injector;
import guice_learning.basic_injection.AppConsumer;
import guice_learning.basic_injection.NotificationService;

public class NotificationClientTest {
    private Injector injector;

    @Before
    public void setUp() throws Exception {
        injector = Guice.createInjector(new AbstractModule() {

            @Override
            protected void configure() {
                bind(NotificationService.class).to(guice_learning.basic_injection.test.MockSMSService.class);
            }
        });
    }

    @After
    public void tearDown() throws Exception {
        injector = null;
    }

    @Test
    public void test() {
        AppConsumer appTest = injector.getInstance(AppConsumer.class);
        Assert.assertEquals(true, appTest.sendNotification("Hello There", "9898989898"));;
    }
}
