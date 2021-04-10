package com.example.lab3

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.lab3.News.News

class NewsListAdapter(private val newsList: Array<News>,private val onClickCallback: (Int) -> Unit ) : RecyclerView.Adapter<NewsListAdapter.NewsViewHolder>() {

    class NewsViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)  {
        val headerTextView: TextView = itemView.findViewById(R.id.list_item_header)
        val dateTextView: TextView = itemView.findViewById(R.id.list_item_date)
        val cutTextView: TextView = itemView.findViewById(R.id.list_item_cut)
        val imageView : ImageView = itemView.findViewById(R.id.list_item_img)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): NewsViewHolder {
        val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.view_list_item_layout,parent,false)
        return NewsViewHolder(view)
    }

    override fun getItemCount(): Int {
        return newsList.size
    }

    override fun onBindViewHolder(holder: NewsViewHolder, position: Int) {
        val newsItem = newsList[position]

        holder.headerTextView.text = newsItem.head
        holder.dateTextView.text = newsItem.date
        holder.cutTextView.text = newsItem.cut
        holder.imageView.setImageResource(newsItem.image!!)

        holder.itemView.setOnClickListener {
            onClickCallback(position)
        }
    }
}