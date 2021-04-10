package com.example.lab2

import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.lab2.News.News

class NewsListAdapter(private val newsList: Array<News>) : RecyclerView.Adapter<NewsListAdapter.NewsViewHolder>() {

    class NewsViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val headerTextView: TextView
        val dateTextView: TextView
        val cutTextView: TextView
        val imageView : ImageView

        init {
            headerTextView = itemView.findViewById(R.id.list_item_header)
            dateTextView = itemView.findViewById(R.id.list_item_date)
            cutTextView = itemView.findViewById(R.id.list_item_cut)
            imageView = itemView.findViewById(R.id.list_item_img)
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): NewsViewHolder {
        val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.list_item_layout,parent,false)
        return NewsViewHolder(view)
    }

    override fun getItemCount(): Int {
        return newsList.size * 1000
    }

    override fun onBindViewHolder(holder: NewsViewHolder, position: Int) {
        val newsItem:News = newsList[position % newsList.size]
        holder.headerTextView.text = newsItem.head
        holder.dateTextView.text = newsItem.date
        holder.cutTextView.text = newsItem.cut
        holder.imageView.setImageResource(newsItem.image!!)
    }
}