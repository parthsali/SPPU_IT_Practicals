import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css'],
})
export class LoginComponent {
  loginData = {
    email: '',
    password: '',
  };

  constructor(private router: Router) {}

  login() {
    if (this.loginData.email === '') {
      alert('Please enter Email');
      return;
    }

    if (this.loginData.password === '') {
      alert('Please enter Password');
      return;
    }

    const data = fetch('http://localhost:8000/api/auth/login', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(this.loginData),
    })
      .then((response) => {
        if (response.status === 401) {
          alert('Invalid Credentials');
          return;
        }
        return response.json();
      })
      .then((data) => {
        if (data.message == 'User not found') {
          alert('User not found');
          return;
        }
        alert(data.message);
        localStorage.setItem('user', JSON.stringify(data.user));
        this.router.navigate(['/user-details']);
      })
      .catch((err) => {
        console.log(err);
      });
  }
}
