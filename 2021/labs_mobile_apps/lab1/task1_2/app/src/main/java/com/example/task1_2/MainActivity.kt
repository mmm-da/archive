package com.example.task1_2
import android.app.Activity
import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.util.Log
import android.widget.Button

class MainActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.d("task2","MainActivity onCreate() called")
        setContentView(R.layout.main_activity_layout)
    }

    override fun onStart() {
        super.onStart()
        Log.d("task2","MainActivity onStart() called")
        val toDetailActivityButton : Button = findViewById(R.id.to_detail_activity_button)
        val openUrlButton : Button = findViewById(R.id.open_url_button)

        toDetailActivityButton.setOnClickListener {
            startActivity(
                Intent(this,DetailActivity::class.java)
            )
        }

        openUrlButton.setOnClickListener {
            startActivity(
                Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=dQw4w9WgXcQ"))
            )
        }
    }

    override fun onResume() {
        super.onResume()
        Log.d("task2","MainActivity onResume() called")
    }

    override fun onRestart() {
        super.onRestart()
        Log.d("task2","MainActivity onRestart() called")
    }h

    override fun onPause() {
        super.onPause()
        Log.d("task2","MainActivity onPause() called")
    }

    override fun onStop() {
        super.onStop()
        Log.d("task2","MainActivity onStop() called")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d("task2","MainActivity onDestroy() called")
    }

}