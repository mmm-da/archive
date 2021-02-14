import React from "react";
import {
    BrowserRouter,
    Switch,
    Route,
    Redirect
} from "react-router-dom";

import NavBar from "./components/NavBar/NavBar";
import Footer from "./components/Footer/Footer";

import MainView from "./views/MainView/MainView";
import ThingView from "./views/ThingView/ThingView";
import StoragesView from "./views/StoragesView/StoragesView";

import "./css/App.css"



export default function App(){
    return(
        <BrowserRouter>
            <div className="container">
                <NavBar/>
                    <Switch>
                        <Route exact path="/" component={MainView}/>
                        <Route path="/thing" component={ThingView}/>
                        <Route path="/storages" component={StoragesView}/>
                    </Switch>
            </div>
            <Footer/>
        </BrowserRouter>
    )
}