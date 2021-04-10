package com.example.lab3

import android.content.Intent
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.lab3.News.newsList

class NewsListFragment : Fragment() {
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val fragmentView = inflater.inflate(R.layout.fragment_news_list_layout, container, false)
        val recyclerView:RecyclerView = fragmentView.findViewById(R.id.news_recycler_view)

        //Чтоб не забыть!
        //В адаптер передается лямбда-функция c аргументом позицией элемента, которая вызывается при нажатии на элемент.
        recyclerView.adapter = NewsListAdapter(
            newsList()
        ) { newsId ->
            val intent = Intent(activity,NewsActivity::class.java)
            intent.putExtra("newsId",newsId)
            startActivity(intent)
        }
        return fragmentView
    }

}