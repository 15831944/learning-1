package boot_demo.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/persons")
public class PersonController {
    @Autowired PersonMapper personMapper;

    @GetMapping
    public String list(ModelMap model) {
        List<Person> persons = personMapper.getPersons();
        model.put("persons", persons);
        return "list";
    }

    @GetMapping("/{id}")
    public String detail(ModelMap model, @PathVariable Integer id) {
        System.out.println("Detail id: " + id);
        Person person = personMapper.getPerson(id);
        model.put("person", person);
        return "detail";
    }

    @GetMapping("/form/{id}")
    public String editForm(ModelMap model, @PathVariable Integer id) {
        Person person = personMapper.getPerson(id);
        model.put("person",person);
        return "form";
    }

    @GetMapping("/form")
    public String form(ModelMap model) {
        Person person = new Person();
        model.put("person", person);
        return "form";
    }

    @PostMapping("/form")
    public String submitForm(Person person) {
        System.out.println("Submiting form person id: " + person.getId());
        if(person.getId() != null) {
            personMapper.save(person);
        } else {
            personMapper.insert(person);
        }
        return "redirect:/persons/" + person.getId();
    }


    @GetMapping("/{id}/delete")
    public String deletePerson(@PathVariable Integer id) {
        personMapper.delete(id);
        return "redirect:/persons/";
    }
}

