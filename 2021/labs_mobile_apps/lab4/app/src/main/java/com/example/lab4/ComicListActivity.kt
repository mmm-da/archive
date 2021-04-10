package com.example.lab4
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class ComicListActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_comic_list_layout)
        supportActionBar?.title = "xkcd comics"
    }
}