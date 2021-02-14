package ru.bstu.vt41.mds.coursework.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import ru.bstu.vt41.mds.coursework.models.Section;
import ru.bstu.vt41.mds.coursework.services.SectionService;

import java.util.List;

@RestController
public class SectionController {
    @Autowired
    SectionService service;

    @GetMapping("/sections")
    private List<Section> getAllSections() {
        return service.getAllSections();
    }

    @GetMapping("/sections_in_storage/{storageId}")
    private List<Section> getSectionsInStorage(@PathVariable("storageId") int storageId) {
        return service.getSectionsInStorage(storageId);
    }

    @GetMapping("/sections/{id}")
    private Section getSection(@PathVariable("id") int id) {
        return service.getSectionById(id);
    }

    @DeleteMapping("/sections/{id}")
    private void deleteSection(@PathVariable("id") int id) {
        service.delete(id);
    }

    @PostMapping("/sections")
    private int saveStorage(@RequestBody Section section) {
        service.saveOrUpdate(section);
        return section.getId();
    }
}