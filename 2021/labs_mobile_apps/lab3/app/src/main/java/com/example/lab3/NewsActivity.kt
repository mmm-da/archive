package com.example.lab3

import android.os.Bundle
import android.os.PersistableBundle
import androidx.appcompat.app.AppCompatActivity
import androidx.fragment.app.Fragment

class NewsActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_news_layout)



        supportActionBar?.hide()
    }

    // В задании сказано сделать activity с фрагментом добавленным через XML,
    // как добавить данные в такой фрагмент я не знаю

    override fun onAttachFragment(fragment: Fragment) {
        super.onAttachFragment(fragment)
        if (fragment.id == R.id.fragment_news){
            fragment.arguments = intent.extras
        }
    }
}