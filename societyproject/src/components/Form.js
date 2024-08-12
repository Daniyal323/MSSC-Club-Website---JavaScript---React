import "./FormStyles.css"

//import React from 'react'
import React, { useRef } from 'react';
import emailjs from '@emailjs/browser';

import { ToastContainer, toast } from 'react-toastify';
import 'react-toastify/dist/ReactToastify.css';

const Form = () => {

    const form = useRef(null);

    const sendEmail = (e) => {
      e.preventDefault();
  
      emailjs.sendForm('service_bf4jl0g', 'template_xmc7fkq', form.current, 'NqNcmFduZXRZL_Dq3')
        .then((result) => {
            console.log(result.text);
        }, (error) => {
            console.log(error.text);
        });
    };

    const diffToast=()=>{
        toast.success("Message sent!", {
            position: "top-center"
        })
    }

  return (
    <div className="form">
        <form ref={form} onSubmit={sendEmail}>
            <label>Name</label>
            <input type="text" name="user_name" />
            <label>Email</label>
            <input type="email" name="user_email" />
            <label>Message</label>
            <textarea name="message" placeholder="Type your Message" />
            <input type="submit" className="btn" value="Send" onClick={diffToast} />
        </form>
        <ToastContainer />
    </div>
  )
}

export default Form