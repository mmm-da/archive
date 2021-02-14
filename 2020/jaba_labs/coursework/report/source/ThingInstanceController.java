package ru.bstu.vt41.mds.coursework.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import ru.bstu.vt41.mds.coursework.models.Thing;
import ru.bstu.vt41.mds.coursework.models.ThingInstance;
import ru.bstu.vt41.mds.coursework.services.ThingInstanceService;
import ru.bstu.vt41.mds.coursework.services.ThingService;

import java.util.List;

@RestController
public class ThingInstanceController {
    @Autowired
    ThingInstanceService service;

    @GetMapping("/instances")
    private List<ThingInstance> getAllThingInstance() {
        return service.getAllThingInstances();
    }

    @GetMapping("/instances_in_section/{sectionId}")
    private List<ThingInstance> getThingInstancesInSection(@PathVariable("sectionId") int sectionId) {
        return service.getThingInstancesInSection(sectionId);
    }

    @GetMapping("/instances_of_thing/{thingId}")
    private List<ThingInstance> getInstancesOfThing(@PathVariable("thingId") int thingId) {
        return service.getThingInstancesInSection(thingId);
    }

    @GetMapping("/instances/{id}")
    private ThingInstance getThingInstance(@PathVariable("id") int id) {
        return service.getThingInstancesById(id);
    }

    @DeleteMapping("/instances/{id}")
    private void deleteThingInstance(@PathVariable("id") int id) {
        service.delete(id);
    }

    @PostMapping("/instances")
    private int saveThingInstance(@RequestBody ThingInstance instance) {
        service.saveOrUpdate(instance);
        return instance.getId();
    }
}
