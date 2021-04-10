package com.example.lab2.News

import android.content.res.Resources
import com.example.lab2.R

fun newsList(): Array<News>{
    return arrayOf(
            News(
                    head= "Samsung представила игровые Mini-LED мониторы Odyssey, телевизоры Neo QLED и огромные micro-LED панели",
                    date = "вчера в 20:38",
                    cut = "Samsung провела онлайн-презентацию, посвящённую дисплеям, на которой представила обновления линеек мониторов и ТВ на 2021 год. Мы выбрали из анонсов главное.",
                    image = R.drawable.news1
            ),
            News(
                    head= "Microsoft представила Mesh - сервис-среду дополненной реальности для общения и взаимодействия людей",
                    date = "50 минут назад",
                    cut = "Корпорация планирует создать \"новое слово в виртуальной реальности\" на основе платформы, которую уже прозвали Teams из будущего.",
                    image = R.drawable.news2
            ),
            News(
                    head= "The Last of Us Part II стала лидером по числу номинаций на BAFTA Games Awards 2021",
                    date = "вчера в 14:28",
                    cut = "Организаторы BAFTA Games Awards опубликовали полный список номинантов на свою премию. Церемония вручения наград пройдёт 25 марта в онлайн-формате.",
                    image = R.drawable.news3
            ),
            News(
                    head= "Blasphemous преодолела отметку в миллион игроков",
                    date = "вчера в 14:14",
                    cut = "Разработчики из студии The Game Kitchen, которая выпустила Blasphemous, объявили о миллионе проданных копий игры в специальном видео.",
                    image = R.drawable.news4
            ),
            News(
                    head= "Sony прекратит продавать и сдавать в прокат фильмы и сериалы в PS Store с 31 августа",
                    date = "вчера в 16:17",
                    cut = "Компания объяснила это изменениями в поведении потребителей — теперь они предпочитают смотреть кино и телешоу в стриминговых сервисах.",
                    image = R.drawable.news5
            ),
            News(
                    head= "В Nioh 2 на ПК добавили правильные подсказки для игры на клавиатуре и мыши",
                    date = "вчера в 13:30",
                    cut = "Почти через месяц после выхода ПК-версии.",
                    image = R.drawable.news6
            ),
            News(
                    head= "F1 | Презентация Alpine A521",
                    date = "вчера в 19:24",
                    cut = "Alpine F1 представили свой новый болид - Alpine A521",
                    image = R.drawable.news7
            ),
            News(
                    head= "Roguelite-платформер ScourgeBringer выйдет на PS4 и PS Vita 22 апреля",
                    date = "вчера в 19:16",
                    cut = "Издатель Dear Villagers объявил в Твиттере о том, что платформер ScourgeBringer от французкой студии Flying Oak Games выйдет на PlayStation 4 и PlayStation Vita уже 22 апреля.",
                    image = R.drawable.news8
            ),
            News(
                    head= "Total Film: новые кадры из «Годзилла против Конга»",
                    date = "вчера в 18:10",
                    cut = "Фильм выйдет 26 марта 2021 года одновременно в кинотеатрах и в стриминговом сервисе HBO Max.",
                    image = R.drawable.news9
            ),
            News(
                    head= "Ratchet and Clank стала бесплатной в PS Store в рамках программы Play at Home",
                    date = "вчера в 07:14",
                    cut = "Игру можно забрать до конца марта — она навсегда останется в библиотеке.",
                    image = R.drawable.news10
            )
    )
}