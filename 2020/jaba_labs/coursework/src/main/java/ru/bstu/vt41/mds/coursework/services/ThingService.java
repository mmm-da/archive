package ru.bstu.vt41.mds.coursework.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.bstu.vt41.mds.coursework.models.Thing;
import ru.bstu.vt41.mds.coursework.repos.ThingRepo;

import java.util.ArrayList;
import java.util.List;

@Service
public class ThingService {
    @Autowired
    ThingRepo repo;
    public List<Thing> getAllThings() {
        List<Thing> things = new ArrayList<>();
        repo.findAll().forEach(things::add);
        return things;
    }

    public Thing getThingById(int id) {
        return repo.findById(id).get();
    }

    public void saveOrUpdate(Thing thing) {
        repo.save(thing);
    }

    public void delete(int id) {
        repo.deleteById(id);
    }
}
