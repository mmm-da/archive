INSERT INTO storage (id,name) VALUES
(1,'Хранилище 1'),
(2,'Хранилище 2'),
(3,'Хранилище 3');

INSERT INTO thing (id,name) VALUES
(1,'Штука 1'),
(2,'Штука 2'),
(3,'Штука 3');

INSERT INTO section (id,name,storage_id) VALUES
(1,'Секция 1',1),
(2,'Секция 2',1),
(3,'Секция 3',1),
(4,'Секция 4',2);

INSERT INTO thing_instance (id,count,thing_id,section_id) VALUES
(1,10,1,1),
(2,11,2,2),
(3,12,2,3),
(4,13,1,1),
(5,14,2,2),
(6,15,1,3),
(7,16,1,1),
(8,17,2,2),
(9,18,2,3),
(10,19,1,1),
(11,20,2,2),
(12,0,1,3);