import React from "react";
import SearchBar from "../../components/SearchBar/SearchBar";
import ThingsList from "../../components/ThingsList/ThingsList";
import "../css/View.css"

export default function AuthMainView(props){
    return(
        <div className="view">
            <h1 className="title">Не знаешь где лежит штука, можешь посмотреть тут</h1>
            <SearchBar/>
            <ThingsList/>
        </div>
    )

}