// src/app/user.service.ts

import { Injectable } from '@angular/core';

@Injectable({
    providedIn: 'root'
})
export class UserService {
    private users: any[] = [];

    registerUser(user: any) {
        // Simulate saving user data to a database
        this.users.push(user);
    }

    loginUser(username: string, password: string): boolean {
        // Simulate user authentication
        const user = this.users.find(u => u.username === username && u.password === password);
        return !!user; // Return true if user is found, false otherwise
    }

    getUserData(username: string): any {
        // Simulate fetching user data from a database
        return this.users.find(u => u.username === username);
    }
}
