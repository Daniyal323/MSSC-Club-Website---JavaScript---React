import React from 'react'

import Navbar from '../components/Navbar.js'
import HeroImg2 from '../components/HeroImg2.js'
import Footer from "../components/Footer"
import EventsList from '../components/EventsList.js'
import Work from '../components/Work.js'

const Events = () => {
  return (
    <div>
      <Navbar />
      <HeroImg2 heading="EVENTS." text="Upcoming Events"/>
      <Work />
      <Footer />
    </div>
  )
}

export default Events