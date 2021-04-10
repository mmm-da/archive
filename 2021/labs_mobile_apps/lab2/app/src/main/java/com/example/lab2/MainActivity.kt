package com.example.lab2
import android.app.Activity
import android.os.Bundle
import android.os.PersistableBundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.lab2.News.newsList

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.main_activity_layout)

        supportActionBar?.title = "Новости"

        val newsRecyclerView: RecyclerView = findViewById(R.id.news_recycler_view)
        val newsAdapter = NewsListAdapter(newsList())
        newsRecyclerView.adapter = newsAdapter
    }
}