package ru.bstu.vt41.mds.coursework.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.bstu.vt41.mds.coursework.models.Section;
import ru.bstu.vt41.mds.coursework.repos.SectionRepo;

import java.util.ArrayList;
import java.util.List;

@Service
public class SectionService {
    @Autowired
    SectionRepo repo;
    public List<Section> getAllSections() {
        List<Section> sections = new ArrayList<>();
        repo.findAll().forEach(sections::add);
        return sections;
    }

    public List<Section> getSectionsInStorage(int storageId){
        List<Section> sections = new ArrayList<>();
        repo.findAll().forEach(section -> {
            if (section.getStorage().getId() == storageId){
                sections.add(section);
            }
        });
        return sections;
    }

    public Section getSectionById(int id) {
        return repo.findById(id).get();
    }

    public void saveOrUpdate(Section section) {
        repo.save(section);
    }

    public void delete(int id) {
        repo.deleteById(id);
    }
}
