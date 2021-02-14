import React from "react";
import {
    BrowserRouter as Router,
    Switch,
    Route
} from "react-router-dom";

import NavBar from "./components/NavBar/NavBar";
import Footer from "./components/Footer/Footer";
import RegisterView from "./views/RegisterView/RegisterView";
import MainView from "./views/MainView/MainView";
import AuthView from "./views/AuthView/AuthView";
import ThingView from "./views/ThingView/ThingView";

import "./css/App.css"

export default function App(){
    return(
        <Router>
            <div className="container">
                <NavBar/>
                    <Switch>
                        <Route exact path="/" component={MainView}/>
                        <Route path="/auth" component={AuthView}/>
                        <Route path="/register" component={RegisterView}/>
                        <Route path="/thing" component={ThingView}/>
                    </Switch>
            </div>
            <Footer/>
        </Router>
    )
}