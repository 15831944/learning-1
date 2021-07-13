package boot_demo.demo;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface PersonMapper {
    @Select("SELECT * FROM person")
    List<Person> getPersons();

    @Select("SELECT * FROM person WHERE id = #{id}")
    Person getPerson(Integer id);

    @Insert("INSERT INTO person(first_name, last_name, place) " +
            " VALUES (#{firstName}, #{lastName}, #{place})")
    @Options(useGeneratedKeys = true)
    void insert(Person person);

    @Update("UPDATE person SET first_name = #{firstName}, last_name= #{lastName}, " + " place = #{place} WHERE id = #{id}")
    void save(Person person);

    @Delete("DELETE FROM person WHERE id=#{id}")
    void delete(Integer id);
}
