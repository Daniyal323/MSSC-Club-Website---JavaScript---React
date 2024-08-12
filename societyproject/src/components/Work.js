import "./EventsListStyles.css"
import EventsList from "./EventsList"
import workcarddata from "./workcarddata"

import React from 'react'

const work = () => {
  return (
    <div className="work-container">
        <h1 className="projects-heading">Events</h1>
        <div className="project-container">
            {workcarddata.map((val,ind) =>{
                return(
                    <EventsList 
                    key={ind}
                    imgsrc={val.imgsrc}
                    text={val.text}
                    register={val.view}
                    view={val.view}
                    />
                )
            })}
        </div>
    </div>
  )
}

export default work