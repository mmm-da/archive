package ru.bstu.vt41.mds.coursework.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.bstu.vt41.mds.coursework.models.Storage;
import ru.bstu.vt41.mds.coursework.repos.StorageRepo;

import java.util.ArrayList;
import java.util.List;

@Service
public class StorageService {
    @Autowired
    StorageRepo repo;

    public List<Storage> getAllStorages() {
        List<Storage> storages = new ArrayList<>();
        repo.findAll().forEach(storages::add);
        return storages;
    }

    public Storage getStorageById(int id) {
        return repo.findById(id).get();
    }

    public void saveOrUpdate(Storage storage) {
        repo.save(storage);
    }

    public void delete(int id) {
        repo.deleteById(id);
    }
}
