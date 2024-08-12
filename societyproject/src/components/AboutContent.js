import "./AboutContentStyles.css"

import React from 'react'

import {Link} from 'react-router-dom'
import logo from '../assets/community.jpg'
import UMTlogo from '../assets/join.jpeg'

const AboutContent = () => {
  return (
    <div className="about">
        <div className="left">
            <h1>Our Mission</h1>
            <p>Our mission is to make a community
                where junior and senior game developers,
                designers, game artist and game story teller
                can interact with each other to gain new skills
                and be creative.
            </p>
            <Link to={"/contact"}>
                <button className="btn">Contact</button>
            </Link>
        </div>
        <div className="right">
            <div className="img-container">
                <div className="img-stack bottom">
                    <img src={logo} className="img" alt="true"/>
                </div>
                <div className="img-stack top">
                    <img src={UMTlogo} className="img" alt="true"/>
                </div>
            </div>
        </div>
    </div>
  )
}

export default AboutContent