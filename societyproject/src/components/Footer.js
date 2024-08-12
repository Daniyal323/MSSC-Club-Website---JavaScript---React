import "./FooterStyles.css"

import React from 'react'

import { FaHome, FaPhone, FaMailBulk, FaFacebook, FaInstagram, FaLinkedin } from "react-icons/fa"


const Footer = () => {
    return (
        <div className="footer">
            <div className="footer-container">
                <div className="left">
                    <div className="location">
                        <FaHome size={20} style={{
                            color:
                                "#fff", marginRight: "2rem"
                        }} />
                        <div>
                            <p>C-II Block C 2 Phase 1</p>
                            <p>Joher Town, Lahore, Pakistan.</p>
                        </div>
                    </div>
                    <div className="phone">
                    <h4><FaPhone size={20} style={{color:
                    "#fff", marginRight: "2rem"}} />
                    0309-4048956</h4> 
                    </div>
                    <div className="email">
                    <h4><FaMailBulk size={20} style={{color:
                    "#fff", marginRight: "2rem"}} />
                    daniyaljawad77@gmail.com</h4>
                    </div>
                </div>
                <div className="right">
                    <h4>About the society</h4>
                    <p>Our mission is to promote  
                    game developement in Pakistan.
                    </p>
                    <div className="social">
                    <FaFacebook 
                        size={30} 
                        style={{
                        color:"#fff", marginRight: "1rem"
                        }} />
                    <FaInstagram 
                        size={30} 
                        style={{
                        color:"#fff", marginRight: "1rem"
                        }} />
                    <FaLinkedin 
                        size={30} 
                        style={{
                        color:"#fff", marginRight: "1rem"
                        }} />
                    </div>
                </div>
            </div>
        </div>
    )
}

export default Footer