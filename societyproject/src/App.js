import React from "react";
import "./index.css"
import Home from "./routerPages/Home"
import Events from "./routerPages/Events"
import About from "./routerPages/About"
import Contact from "./routerPages/Contact"
import { Route, Routes } from "react-router-dom";

function App() {
  return (
    <>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/events" element={<Events />} />
        <Route path="/about" element={<About />} />
        <Route path="/contact" element={<Contact />} />
      </Routes>
    </>
  );
}

export default App;