import React,{ useRef } from "react";
import {Link} from "react-router-dom";

import "../css/View.css"
import StorageList from "../../components/StorageList/StorageList";


export default function StoragesView(){
    return(
        <main className="view">
            <div className="title-container">
                <h1 className="title">Хранилища</h1>
                <button>Добавить хранилище</button>
            </div>
            <StorageList/>
        </main>
    )
}