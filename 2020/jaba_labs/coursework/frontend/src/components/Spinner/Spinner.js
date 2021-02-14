import React from 'react'
import './Spinner.css'

export function Spinner(props){
    var className = 'medium-spinner';
    var classNameColor = '';
    switch (props.spinnerSize){
        case('big'):      className = 'big-spinner';    break;
        case('medium'):   className = 'medium-spinner'; break;
        case('small'):    className = 'small-spinner';  break;
    }

    if (props.invertedColor){
        classNameColor += ' inverted'
    }

    return (
        <div className={className}>
            <div className={"double-bounce1"+classNameColor}></div>
            <div className={"double-bounce2"+classNameColor}></div>
        </div>
    )
}
