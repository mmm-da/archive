package com.example.lab4

import android.content.Intent
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.lab4.Comic.ComicListElement
import com.google.android.material.progressindicator.CircularProgressIndicator
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class ComicListFragment : Fragment() {
    private val comicModel = ComicModel()

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val fragmentView = inflater.inflate(R.layout.fragment_comic_list_layout, container, false)

        val recyclerView = fragmentView.findViewById<RecyclerView>(R.id.comic_recycler_view)
        val spinner = fragmentView.findViewById<CircularProgressIndicator>(R.id.comic_list_spinner)
        CoroutineScope(Dispatchers.Main).launch {
            val comicList = comicModel.getRandomComicList()

            spinner.visibility = View.GONE
            recyclerView.visibility = View.VISIBLE

            recyclerView.adapter = ComicListAdapter(
                comicList
            ) { comicId ->
                val intent = Intent(activity,ComicActivity::class.java)
                intent.putExtra("comicId",comicId)
                startActivity(intent)
            }
        }

        return fragmentView
    }

}