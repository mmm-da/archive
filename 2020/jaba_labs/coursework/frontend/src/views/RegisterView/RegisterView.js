import React,{ useRef } from "react";
import {Link} from "react-router-dom";

import "../css/View.css"


export default function RegisterView(){
    return(
        <main className="view">
            <h1 className="title">Зарегистрируйся чтобы получить возможность</h1>
                <p className="hidden-text">наверное, если не будет лень</p>
            <h1 className="title">навести порядок в хранилищах своего хлама</h1>
            
            <form onSubmit={e => e.preventDefault()}>
                <div className="form-input">
                    <p>Имя пользователя</p>
                    <input
                        name='username' 
                    />
                    <p>Пароль</p>
                    <input
                        name='password'
                        type="password"
                    />
                    <p>Повторите пароль</p>
                    <input
                        name='match_password'
                        type="password"
                    />
                </div>
                <button type="submit" >
                    Зарегистрироватся
                </button>
            </form>

            <p>или можно просто <Link to="/signin">войти</Link></p>
        </main>
    )
}