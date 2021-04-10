package com.example.task1_2
import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button

class DetailActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.d("task2","DetailActivity onCreate() called")
        setContentView(R.layout.detail_activity_layout)
    }

    override fun onStart() {
        super.onStart()
        Log.d("task2","DetailActivity onStart() called")
    }

    override fun onResume() {
        super.onResume()
        Log.d("task2","DetailActivity onResume() called")
    }

    override fun onRestart() {
        super.onRestart()
        Log.d("task2","DetailActivity onRestart() called")
    }

    override fun onPause() {
        super.onPause()
        Log.d("task2","DetailActivity onPause() called")
    }

    override fun onStop() {
        super.onStop()
        Log.d("task2","DetailActivity onStop() called")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d("task2","DetailActivity onDestroy() called")
    }
}

