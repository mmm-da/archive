package ru.bstu.vt41.mds.coursework.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import ru.bstu.vt41.mds.coursework.models.Storage;
import ru.bstu.vt41.mds.coursework.services.StorageService;

import java.util.List;

@CrossOrigin
@RestController
public class StorageController {
    @Autowired
    StorageService service;

    @GetMapping("/storages")
    private List<Storage> getAllStorages() {
        return service.getAllStorages();
    }

    @GetMapping("/storages/{id}")
    private Storage getStorage(@PathVariable("id") int id) {
        return service.getStorageById(id);
    }

    @DeleteMapping("/storages/{id}")
    private void deleteStorage(@PathVariable("id") int id) {
        service.delete(id);
    }

    @PostMapping("/storages")
    private int saveStorage(@RequestBody Storage storage) {
        service.saveOrUpdate(storage);
        return storage.getId();
    }
}