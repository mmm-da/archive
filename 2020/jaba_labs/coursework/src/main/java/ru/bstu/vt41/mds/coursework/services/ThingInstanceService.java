package ru.bstu.vt41.mds.coursework.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.bstu.vt41.mds.coursework.models.Thing;
import ru.bstu.vt41.mds.coursework.models.ThingInstance;
import ru.bstu.vt41.mds.coursework.repos.ThingInstanceRepo;
import ru.bstu.vt41.mds.coursework.repos.ThingRepo;

import java.util.ArrayList;
import java.util.List;

@Service
public class ThingInstanceService {
    @Autowired
    ThingInstanceRepo repo;
    public List<ThingInstance> getAllThingInstances() {
        List<ThingInstance> instances = new ArrayList<>();
        repo.findAll().forEach(instances::add);
        return instances;
    }

    public List<ThingInstance> getThingInstancesInSection(int sectionId){
        List<ThingInstance> instances = new ArrayList<>();
        repo.findAll().forEach(instance -> {
            if (instance.getSection().getId() == sectionId){
                instances.add(instance);
            }
        });
        return instances;
    }

    public List<ThingInstance> getInstancesForThing(int thingId){
        List<ThingInstance> instances = new ArrayList<>();
        repo.findAll().forEach(instance -> {
            if (instance.getThing().getId() == thingId){
                instances.add(instance);
            }
        });
        return instances;
    }

    public ThingInstance getThingInstancesById(int id) {
        return repo.findById(id).get();
    }

    public void saveOrUpdate(ThingInstance instance) {
        repo.save(instance);
    }

    public void delete(int id) {
        repo.deleteById(id);
    }
}
