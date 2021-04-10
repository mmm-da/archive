package com.example.lab3

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.lab3.News.newsList

class NewsFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val fragmentView = inflater.inflate(R.layout.fragment_news_layout, container, false)

        val news = newsList()[
                arguments?.getInt("newsId")!!
        ]

        val newsImage = fragmentView.findViewById<ImageView>(R.id.news_img)
        val newsHeader = fragmentView.findViewById<TextView>(R.id.news_header)
        val newsDate = fragmentView.findViewById<TextView>(R.id.news_date)
        val newsText = fragmentView.findViewById<TextView>(R.id.news_text)

        newsHeader.text = news.head
        newsDate.text = news.date
        newsText.text = (news.cut + "\n" + news.fullText)
        newsImage.setImageResource(news.image!!)

        return fragmentView
    }

}