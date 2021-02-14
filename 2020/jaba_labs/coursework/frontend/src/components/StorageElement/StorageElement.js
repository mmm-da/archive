import React from "react";
import {Link} from "react-router-dom";
import './StorageElement.css'
import {Spinner} from "../Spinner/Spinner";

export default function StorageElement(props){
    const data = props.storageInfo

    if (data == null){
        return <Spinner spinnerSize='small'/>
    }else{
        return(
            <Link to={"/storage/"+ data.id}>
                <div className = "storage-element">
                    <div className= "storage-element-header">
                        {data.name}
                    </div>
                    <div className= "storage-element-section-counter">
                        {"Количество секций: "+ data.sections.length}
                    </div>
                </div>
            </Link>
        )
    }

}