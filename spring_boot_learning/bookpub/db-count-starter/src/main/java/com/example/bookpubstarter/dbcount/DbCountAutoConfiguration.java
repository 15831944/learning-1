package com.example.bookpubstarter.dbcount;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.actuate.health.CompositeHealthIndicator;
import org.springframework.boot.actuate.health.HealthAggregator;
import org.springframework.boot.actuate.health.HealthIndicator;
import org.springframework.boot.autoconfigure.condition.ConditionalOnMissingBean;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.repository.CrudRepository;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

@Configuration
public class DbCountAutoConfiguration {
    @Autowired
    private HealthAggregator statusAggregator;
    @Bean
    @ConditionalOnMissingBean
    public DbCountRunner dbCountRunner(Collection<CrudRepository> repositories) {
        return new DbCountRunner(repositories);
    }

    @Bean
    @ConditionalOnMissingBean
    public HealthIndicator doCountHealthIndicator(Collection<CrudRepository> repositories) {
        Map<String, HealthIndicator> indicatorMap = new HashMap<>();
        for (CrudRepository repository : repositories) {
            String name = DbCountRunner.getRepositoryName(repository.getClass());
            indicatorMap.put(name, new DBCountHealthIndicator(repository));
        }
        CompositeHealthIndicator compositeHealthIndicator = new CompositeHealthIndicator(statusAggregator, indicatorMap);
        return compositeHealthIndicator;
    }
}
