import React from "react"

import "../css/View.css"
import "./ThingView.css"

export default function ThingView(){
    return(
        <main className="view">
            <div className="thing-page-header">
                <svg className="things-list-element-icon"
                    viewBox="0 0 16 16"
                    fill="currentColor" xmlns="http://www.w3.org/2000/svg">
                    <path fill-rule="evenodd" d="M11 2H5a3 3 0 0 0-3 3v6a3 3 0 0 0 3 3h6a3 3 0 0 0 3-3V5a3 3 0 0 0-3-3zM5 1a4 4 0 0 0-4 4v6a4 4 0 0 0 4 4h6a4 4 0 0 0 4-4V5a4 4 0 0 0-4-4H5z"/>
                </svg>
                <h1>Штука</h1>
            </div>
            <div className="thing-page-body">
                <div className="thing-page-content">
                    <h2>Подробная информация</h2>
                    <table>
                        <tbody>
                            <tr>
                                <td>Свойство 1</td>
                                <td>1</td>
                            </tr>
                            <tr>
                                <td>Свойство 2</td>
                                <td>2</td>
                            </tr>
                            <tr>
                                <td>Свойство 3</td>
                                <td>3</td>
                            </tr>
                            <tr>
                                <td>Где купить?</td>
                                <td><a href="https://google.com">google.com</a></td>
                            </tr>
                        </tbody>
                    </table>
                    <h2>Заметки</h2>
                    <div className="thing-page-content-block-body">
                        Заметки, заметки, заметки
                    </div>
                </div>
                <div className="thing-page-content">
                    <h2>Где лежит?</h2>
                    <table>
                        <tbody>
                            <tr>
                                <td>Ящик 1 секция А1</td>
                                <td className="thing-table-count"> 2 шт </td>
                            </tr>
                            <tr>
                                <td>Ящик 1 секция B4</td>
                                <td className="thing-table-count">200 шт</td>
                            </tr>
                            <tr>
                                <td>Ящик 32 секция G10</td>
                                <td className="thing-table-count">96 шт</td>
                            </tr>
                        </tbody>
                    </table>
                </div>
            </div>
        </main>
    )
}