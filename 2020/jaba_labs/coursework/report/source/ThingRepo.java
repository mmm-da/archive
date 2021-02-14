package ru.bstu.vt41.mds.coursework.repos;

import org.springframework.data.repository.CrudRepository;
import ru.bstu.vt41.mds.coursework.models.Thing;

public interface ThingRepo extends CrudRepository<Thing,Integer> {}
