import "./HeroImgStyles.css";

import React from 'react'
import { Link } from "react-router-dom";

import IntroImg from "../assets/intro.jpg"

const HeroImg = () => {
  return (
    <div className="hero">
      <div className="mask">
        <img className="intro-img" src={IntroImg}
        alt="IntroImg"/>
      </div>
      <div className="content">
        <h1>Mindstorm Studios</h1>
        <p>Student Chapter | UMT-LHR</p>
        <div>
          <Link to="/events" className="btn">Events</Link>
          <Link to="/contact" className="btn btn-light">Contact</Link>
        </div>
      </div>
    </div>
  )
}

export default HeroImg