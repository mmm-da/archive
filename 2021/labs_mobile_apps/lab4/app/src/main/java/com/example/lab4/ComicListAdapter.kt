package com.example.lab4

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.lab4.Comic.ComicListElement
import com.squareup.picasso.Picasso
import java.time.LocalDate
import java.util.*
import kotlin.collections.ArrayList

class ComicListAdapter(private val comicList: ArrayList<ComicListElement>, private val onClickCallback: (Int) -> Unit ) : RecyclerView.Adapter<ComicListAdapter.ComicViewHolder>() {

    class ComicViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)  {
        val titleTextView: TextView = itemView.findViewById(R.id.list_item_title)
        val dateTextView: TextView = itemView.findViewById(R.id.list_item_date)
        val altTextView: TextView = itemView.findViewById(R.id.list_item_alt)
        val imageView : ImageView = itemView.findViewById(R.id.list_item_img)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ComicViewHolder {
        val view = LayoutInflater.from(parent.context)
                .inflate(R.layout.view_list_item_layout,parent,false)
        return ComicViewHolder(view)
    }

    override fun getItemCount(): Int {
        return comicList.size
    }

    override fun onBindViewHolder(holder: ComicViewHolder, position: Int) {
        val comicItem = comicList[position]

        holder.titleTextView.text = comicItem.safe_title
        holder.dateTextView.text = LocalDate.of(comicItem.year,comicItem.month,comicItem.day).toString()
        holder.altTextView.text = comicItem.alt
        Picasso.get().load(comicItem.img).into(holder.imageView)

        holder.itemView.setOnClickListener {
            onClickCallback(comicItem.num)
        }
    }
}