package com.example.lab4

import android.util.Log
import androidx.annotation.WorkerThread
import com.example.lab4.Comic.*
import io.ktor.client.HttpClient
import io.ktor.client.features.json.GsonSerializer
import io.ktor.client.features.json.JsonFeature
import io.ktor.client.request.get
import io.ktor.client.engine.cio.*
import kotlin.random.Random

class ComicModel{
    private val baseURL = "https://xkcd.com"
    private val maxID = 2438
    private val itemCount = 5

    private val httpClient = HttpClient(CIO){
        install(JsonFeature){
            serializer = GsonSerializer()
        }
    }

    @WorkerThread
    // Я не совсем разобрался как вернуть данные есть сделать вызовы ktor через withContext(Dispatcher.IO)
    suspend fun getRandomComicList(): ArrayList<ComicListElement> {
        val comicList = arrayListOf<ComicListElement>()
            for (id in maxID downTo maxID - itemCount){
                val comic = httpClient.get<ComicListElement>("$baseURL/$id/info.0.json")
                comicList.add(comic)
            }
        return comicList
    }

    @WorkerThread
    suspend fun getComicById(id:Int): Comic {
        return httpClient.get<Comic>("$baseURL/$id/info.0.json")
    }
}