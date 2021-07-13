package com.example.bookpubstarter.dbcount;

import org.springframework.boot.actuate.health.Health;
import org.springframework.boot.actuate.health.HealthIndicator;
import org.springframework.data.repository.CrudRepository;

public class DBCountHealthIndicator implements HealthIndicator {

    private CrudRepository repository;

    public DBCountHealthIndicator(CrudRepository repository) {
        this.repository = repository;
    }

    @Override
    public Health getHealth(boolean includeDetails) {
        try {
            long count = repository.count();
            if (count >= 0) {
                return Health.up().withDetail("count", count).build();
            } else {
                return Health.unknown().withDetail("count", count).build();
            }
        } catch (Exception ex) {
            return Health.down(ex).build();
        }
    }

    @Override
    public Health health() {
        try {
            long count = repository.count();
            if (count >= 0) {
                return Health.up().withDetail("count", count).build();
            } else {
                return Health.unknown().withDetail("count", count).build();
            }
        } catch (Exception ex) {
            return Health.down(ex).build();
        }
    }
}
