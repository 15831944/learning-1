package guice_learning.serviceprovider;

import com.google.inject.Provider;

public class SMSProvider implements Provider<ServiceConnection> {
    @Override
    public ServiceConnection get() {
        //done some logic to generate the service connection
        ServiceConnection serviceConnection = new ServiceConnection();
        //done some initialization here
        return serviceConnection;
    }
}
