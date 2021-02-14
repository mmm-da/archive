package ru.bstu.vt41.mds.coursework.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import ru.bstu.vt41.mds.coursework.models.Thing;
import ru.bstu.vt41.mds.coursework.services.ThingService;

import java.util.List;

@RestController
public class ThingController {
    @Autowired
    ThingService service;

    @GetMapping("/things")
    private List<Thing> getAllThings() {
        return service.getAllThings();
    }


    @GetMapping("/things/{id}")
    private Thing getThing(@PathVariable("id") int id) {
        return service.getThingById(id);
    }

    @DeleteMapping("/things/{id}")
    private void deleteThing(@PathVariable("id") int id) {
        service.delete(id);
    }

    @PostMapping("/things")
    private int saveThing(@RequestBody Thing person) {
        service.saveOrUpdate(person);
        return person.getId();
    }
}
