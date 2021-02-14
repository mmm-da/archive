import React, {useEffect, useState} from "react";
import {Link} from "react-router-dom";
import './StorageList.css'
import StorageElement from "../StorageElement/StorageElement";
import {Spinner} from "../Spinner/Spinner";
import axios from 'axios';

export default function StorageList(props){

    const [components,setComponents] = useState(null);

    const getStorages = async () =>{
        try{
            const response = await axios({
                method: 'get',
                url: 'localhost:8080/storages',
            });
            console.log(response)
            return Promise.resolve(response.data);
        }
        catch (e){
            return null
        }
    }

    useEffect(
        ( )=> {
                getStorages().then(
                    data => {setComponents(
                        data.map( data => <StorageElement key={data.id} storageInfo={data}/>)
                    )}
                )
        },[])

    return(
        <ul className="storage-list">
            {components}
        </ul>
    )
}