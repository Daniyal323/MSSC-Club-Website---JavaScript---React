import React from 'react'

import Navbar from '../components/Navbar.js'
import HeroImg2 from '../components/HeroImg2.js'
import Footer from "../components/Footer"
import AboutContent from '../components/AboutContent.js'


const About = () => {
  return (
    <div>
      <Navbar />
      <HeroImg2 heading="ABOUT." text="Our mission"/>
      <AboutContent/>
      <Footer />
    </div>
  )
}

export default About