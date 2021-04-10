package com.example.lab2.News

import androidx.annotation.DrawableRes

data class News(
    val head: String,
    val date: String,
    val cut: String,
    @DrawableRes
    val image: Int?
)
