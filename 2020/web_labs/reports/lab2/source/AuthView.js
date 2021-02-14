import React from "react";
import {Link} from "react-router-dom";
import "../css/View.css"

export default function AuthView(){
    return(
        <main className="view">
            <h1 className="title">Вход в хранилище хлама</h1>
            <div className="text-input">
                <p className="text-input-label">Электронная почта</p>
                <input/>
            </div>
            <div className="text-input">
                <p className="text-input-label">Пароль</p>
                <input/>
            </div>
            <button>Войти</button>
            <p>
                <Link to="/auth">Забыл пароль</Link> че делать?
            </p>
        </main>
    )
}