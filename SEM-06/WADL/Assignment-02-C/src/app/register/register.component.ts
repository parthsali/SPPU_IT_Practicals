import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css'],
})
export class RegisterComponent {
  user = {
    name: '',
    username: '',
    email: '',
    password: '',
    confirmPassword: '',
  };

  constructor(private router: Router) {}

  register() {
    if (this.user.name === '') {
      alert('Please enter Name');
      return;
    }

    if (this.user.username === '') {
      alert('Please enter Username');
      return;
    }

    if (this.user.email === '') {
      alert('Please enter Email');
      return;
    }

    if (this.user.password === '') {
      alert('Please enter Password');
      return;
    }

    if (this.user.confirmPassword === '') {
      alert('Please confirm Password');
      return;
    }

    if (this.user.password !== this.user.confirmPassword) {
      alert('Passwords do not match');
      return;
    }

    const data = fetch('http://localhost:8000/api/auth/register', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(this.user),
    })
      .then((response) => response.json())
      .then((data) => {
        alert(data.message);
        this.router.navigate(['/login']);
      })
      .catch((error) => {
        console.log(error);
      });
  }
}
