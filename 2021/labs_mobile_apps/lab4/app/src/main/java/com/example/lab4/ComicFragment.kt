package com.example.lab4

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.ScrollView
import android.widget.TextView
import androidx.transition.Visibility
import com.example.lab4.Comic.Comic
import com.google.android.material.progressindicator.CircularProgressIndicator
import com.squareup.picasso.Picasso
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import java.time.LocalDate

class ComicFragment : Fragment() {
    private val comicModel = ComicModel()

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val fragmentView = inflater.inflate(R.layout.fragment_comic_layout, container, false)

        val newsImage = fragmentView.findViewById<ImageView>(R.id.comic_img)
        val newsHeader = fragmentView.findViewById<TextView>(R.id.comic_title)
        val newsDate = fragmentView.findViewById<TextView>(R.id.comic_date)
        val newsText = fragmentView.findViewById<TextView>(R.id.comic_transcript)
        val newsAlt = fragmentView.findViewById<TextView>(R.id.comic_alt)

        val comicContainer = fragmentView.findViewById<ScrollView>(R.id.comic_container)
        val spinner = fragmentView.findViewById<CircularProgressIndicator>(R.id.comic_spinner)

        CoroutineScope(Dispatchers.Main).launch {
            var comic = comicModel.getComicById(arguments?.getInt("comicId")!!)

            spinner.visibility = View.GONE
            comicContainer.visibility = View.VISIBLE

            newsHeader.text = comic.title
            newsDate.text = LocalDate.of(comic.year,comic.month,comic.day).toString()
            newsText.text = comic.transcript
            newsAlt.text = comic.alt
            Picasso.get().load(comic.img).into(newsImage)
        }
        return fragmentView
    }
}