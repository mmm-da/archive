import React from "react";
import {Link} from "react-router-dom";

import "../css/View.css"


export default function RegisterView(){
    return(
        <main className="view">
            <h1 className="title">Зарегистрируйся чтобы получить возможность</h1>
                <p className="hidden-text">наверное, если не будет лень</p>
            <h1 className="title">навести порядок в хранилищах своего хлама</h1>
            <div className="text-input">
                <p className="text-input-label">Электронная почта</p>
                <input/>
            </div>
            <div className="text-input">
                <p className="text-input-label">Придумайте пароль</p>
                <input/>
            </div>
            <div className="text-input">
                <p className="text-input-label">Повторите пароль</p>
                <input/>
            </div>
            <button>Зарегистрироватся</button>
            <p>или можно просто <Link to="/auth">войти</Link></p>
        </main>
    )
}