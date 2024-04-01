import { useState } from "react";

import styles from "./Register.module.css";

const Register = () => {
  const [user, setUser] = useState();
  const [errorMsg, setErrorMsg] = useState("");

  const handleOnChange = (e) => {
    const { name, value } = e.target;
    setUser(() => {
      return {
        ...user,
        [name]: value,
      };
    });
  };

  const handleSubmit = async () => {
    console.log(user);
  };
  return (
    <>
      <div className={styles.main_container}>
        <div className={styles.info_container}>
          <div className={styles.info_center_container}>
            <h1 className={styles.heading}>
              <span className={styles.blue}>Gyan Sparsh</span>
            </h1>
            <h3 className={styles.subheading}>
              An Education Platform for Hearing and
              <span className={styles.blue}>Deaf</span>
              Alike
            </h3>
          </div>
        </div>
        <div className={styles.input_container}>
          <div className={styles.input_center_container}>
            <div className={styles.welcome}>
              <h1>Hey, welcome 👋</h1>
              <h3>Enter the information you entered while registering</h3>
            </div>
            <div className={styles.input_field}>
              <label>Name</label>
              <input onChange={handleOnChange} type="text" name="name" />
            </div>
            <div className={styles.input_field}>
              <label>Email</label>
              <input onChange={handleOnChange} type="text" name="email" />
            </div>
            <div className={styles.input_field}>
              <label>Password</label>
              <input
                onChange={handleOnChange}
                type="password"
                name="password"
              />
            </div>

            <div className={styles.signup_container}>
              <button onClick={handleSubmit} className={styles.signup_btn}>
                Register
              </button>
            </div>
            <div className={styles.footer}>
              <p>
                Don't have account? <a href="/register">Register</a>
              </p>
            </div>
            <div className={styles.line}></div>
          </div>
        </div>
      </div>
    </>
  );
};

export default Register;
