package com.example.bookpub;

import com.netflix.loadbalancer.Server;
import com.netflix.loadbalancer.ServerList;
import org.springframework.cloud.netflix.ribbon.StaticServerList;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class LocalRibbonClientConfiguration {
    @Bean
    public ServerList<Server> riboonServerList() {
        StaticServerList<Server> staticServerList = new StaticServerList<>(new Server("localhost", 2010),
                new Server("localhost", 8081),
                new Server("localhost", 8082));
        return staticServerList;
    }
}
