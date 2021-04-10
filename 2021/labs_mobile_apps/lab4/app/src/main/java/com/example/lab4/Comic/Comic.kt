package com.example.lab4.Comic

data class Comic(
    val num: Int = 1,
    val day: Int = 1,
    val month: Int = 1,
    val year: Int = 2021,
    val safe_title: String = "Заголовок",
    val title: String = "Большой заголовок",
    val img: String = "https://square.github.io/picasso/static/sample.png",
    val alt: String = "Если это появилось, значит что то не работает",
    val transcript: String = "Если это появилось, значит что то не работает"
)

data class ComicListElement(
    val num: Int = 1,
    val day: Int = 1,
    val month: Int = 1,
    val year: Int = 1,
    val safe_title: String = "Заголовок",
    val alt: String = "Если это появилось, значит что то не работает",
    val img: String  = "https://square.github.io/picasso/static/sample.png"

)