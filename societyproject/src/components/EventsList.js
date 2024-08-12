import "./EventsListStyles.css"

import React from 'react'

import OOTA from "../assets/OOTA.jpg"
import { NavLink } from "react-router-dom"

const EventsList = (props) => {
  return (
    <div className="project-card">
                <img src={props.imgsrc} alt="image" />
                <div className="pro-details">
                    <p>{props.text}</p>
                    <div className="pro-btns">
                        <NavLink to={props.register} className="btn">Register</NavLink>
                        <NavLink to={props.view} className="btn">View</NavLink>
                    </div>
                </div>
            </div>
  )
}

export default EventsList