a_is_b("100 rub","price").
a_is_b("90 rub","price").
a_is_b("65 rub","price").
a_is_b("45 rub","price").
a_is_b("30 rub","price").

a_is_b("170","page_count").
a_is_b("90","page_count").
a_is_b("60","page_count").
a_is_b("50","page_count").
a_is_b("95","page_count").
a_is_b("30","page_count").

a_is_b("yes","subscription").
a_is_b("no","subscription").

a_is_b("woman","audience").
a_is_b("man","audience").

a_is_b("auto","magazine").
a_is_b("fashion","magazine").
a_is_b("games","magazine").
a_is_b("photo","magazine").
a_is_b("handmade","magazine").
a_is_b("music","magazine").

a_is_b("auto_info","magazine_info").
a_is_b("fashion_info","magazine_info").
a_is_b("games_info","magazine_info").
a_is_b("photo_info","magazine_info").
a_is_b("handmade_info","magazine_info").
a_is_b("music_info","magazine_info").

part_of("man","auto").
part_of("100 rub","auto").
part_of("170","auto").
part_of("auto_info","auto").
part_of("no","auto").

part_of("woman","fashion").
part_of("90 rub","fashion").
part_of("90","fashion").
part_of("fashion_info","fashion").
part_of("yes","fashion").

part_of("woman","games").
part_of("man","games").
part_of("65 rub","games").
part_of("60","games").
part_of("games_info","games").
part_of("no","games").

part_of("woman","photo").
part_of("45 rub","photo").
part_of("50","photo").
part_of("photo_info","photo").
part_of("yes","photo").

part_of("woman","handmade").
part_of("man","handmade").
part_of("100 rub","handmade").
part_of("95","handmade").
part_of("handmade_info","handmade").
part_of("yes","handmade").

part_of("woman","music").
part_of("man","music").
part_of("30 rub","music").
part_of("30","music").
part_of("music_info","music").
part_of("no","music").

is_a(X,Y) :- a_is_b(X,Y).
is_part(X,Y) :- part_of(X,Y).