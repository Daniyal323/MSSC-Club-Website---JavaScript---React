import "./NavbarStyles.css"

import React, { useState } from "react";
import { Link } from "react-router-dom";

import {FaBars, FaTimes} from "react-icons/fa";

import Logo from "../assets/logo.png"

const Navbar = () => {

const [click, setClick]=useState(false);
const handleClick=()=>setClick(!click);

const [color,setColor]=useState(false);
const changeColor=()=>{
    if(window.screenY>=100){
        setColor(true);
    }else{
        setColor(false);
    }
}

window.addEventListener("scroll",changeColor);

  return ( 
    <div class={color ? "header header-bg": "header"}>
        <Link to={"/"}>
            <img className="logo" src={Logo} alt="LogoImg"/>
            <h2 id="heading">Mindst<span className="word">o</span>rm Studios</h2>
        </Link>
        <ul class={click?"nav-menu active" : "nav-menu"}>
            <li>
                <Link to={"/"}>Home</Link>
            </li>
            <li>
                <Link to={"/events"}>Events</Link>
            </li>
            <li>
                <Link to={"/about"}>About</Link>
            </li>
            <li>
                <Link to={"/contact"}>Contact</Link>
            </li>
        </ul>
        <div className="hamburger" onClick={handleClick}>
            {click ? (
            <FaTimes size={20} style={{color:
                "white"}} />):(
            <FaBars size={20} style={{color:"white"}} />)}
            
            
        </div>
    </div>
  )
}

export default Navbar