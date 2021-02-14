package ru.bstu.vt41.mds.coursework.models;

import lombok.AllArgsConstructor;
import lombok.Data;

import javax.persistence.*;

@Data
@Entity
public class ThingInstance {
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    private Integer id;
    private Long count;

    @ManyToOne(cascade = CascadeType.ALL)
    private Thing thing;

    @ManyToOne(cascade = CascadeType.ALL)
    private Section section;

}

