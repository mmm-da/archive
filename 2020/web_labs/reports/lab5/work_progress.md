В качестве СУБД был использовал PostgreSQL развернутый в Docker контейнере.

Для реализации REST API была использована библиотека Django REST Framework.

Были описаны отображения и сериализаторы для таблиц Thing, Storage, Thing Instance, Thing Category, Section, и настроены URL. (код см. в приложении)

При помощи библиотеки *drf-spectacular* была сгенерирована схема API в формате OpenAPI и размещена статическая страница с документацией на сервисе Github Pages. (https://spam25.github.io/web_labs/docs/)