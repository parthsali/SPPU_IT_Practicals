import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css'],
})
export class LoginComponent {
  loginData = {
    username: '',
    password: '',
  };

  constructor(private router: Router) {}

  login() {
    // Retrieve user data from localStorage
    const storedUserString = localStorage.getItem('user');

    if (storedUserString) {
      const storedUser = JSON.parse(storedUserString);

      // Check if the user exists and the password matches
      if (
        this.loginData.username === storedUser.username &&
        this.loginData.password === storedUser.password
      ) {
        alert('Login successful!');
      } else {
        alert('Invalid credentials. Please try again.');
      }
    } else {
      alert('User not found. Please register.');
    }
    this.router.navigate(['/user-details']);
  }
}
