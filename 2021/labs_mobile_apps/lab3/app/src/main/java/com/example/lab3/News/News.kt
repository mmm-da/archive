package com.example.lab3.News

import androidx.annotation.DrawableRes

data class News(
    val head: String,
    val date: String,
    val cut: String,
    @DrawableRes
    val image: Int?,
    val fullText: String
)
