package aop.advice.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

@Repository("bookDao_new")
public class BookDAO_new_Impl implements  BookDAO_new{

    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public String getDescription(long ISBN) {
        String GET_DESCRIPTION = "select description from book where \"ISBN\"=?";
        String description = jdbcTemplate.queryForObject(GET_DESCRIPTION, new Object[]{ISBN}, String.class);
        return description;
    }
}
