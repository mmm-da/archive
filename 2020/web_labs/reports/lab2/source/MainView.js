import React from "react";
import SearchBar from "../../components/SearchBar/SearchBar";

import "../css/View.css"
import ThingsList from "../../components/ThingsList/ThingsList";

export default function MainView(){
    return(
        <div className="view">
            <h1 className="title">Не знаешь где лежит штука, можешь посмотреть тут</h1>
            <SearchBar/>
            <ThingsList/>
        </div>
    )
}