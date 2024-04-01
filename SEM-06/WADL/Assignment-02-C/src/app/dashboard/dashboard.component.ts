import { Component } from '@angular/core';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrl: './dashboard.component.css',
})
export class DashboardComponent {
  users: any[] = [];

  constructor() {
    this.getUsers();
  }

  getUsers() {
    console.log('Fetching users');
    fetch('http://localhost:8000/api/auth/all')
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        this.users = data;
      })
      .catch((error) => {
        console.log('Error:', error);
      });
  }

  deleteUser(email: string) {
    console.log('Deleting user:', email);
    fetch('http://localhost:8000/api/auth/delete', {
      method: 'DELETE',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ email }),
    })
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        alert(data.message);
        this.getUsers();
      })
      .catch((error) => {
        console.log('Error:', error);
      });
  }

  editUser(email: string) {}
}
