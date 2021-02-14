import React, {useEffect,useState} from 'react'
import {Link} from "react-router-dom";
import './NavBar.css'

export default function NavBar(){
    return(
        <nav className='navbar'>
            <Link to="/things" className="navbar-item">Штуки</Link>
            <Link to="/storages" className="navbar-item">Хранилища</Link>
        </nav>
    );
}