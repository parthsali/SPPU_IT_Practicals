// user-details.component.ts
import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-user-details',
  templateUrl: './user-details.component.html',
  styleUrls: ['./user-details.component.css'],
})
export class UserDetailsComponent implements OnInit {
  user: any;

  constructor(private route: ActivatedRoute) {}

  ngOnInit() {
    // Retrieve user details from localStorage
    var userDetails = localStorage.getItem('user');

    // Parse the user details to JSON
    if (userDetails) {
      this.user = JSON.parse(userDetails);
    }

    // Print user details to the console
    console.log('User Details:', this.user);
  }
}
