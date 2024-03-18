// app.module.ts
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { AppRoutingModule } from './app-routing.module'; // Import the AppRoutingModule
import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { SignupComponent } from './signup/signup.component';

@NgModule({
    declarations: [
        AppComponent,
        LoginComponent,
        SignupComponent,

    ],
    imports: [
        BrowserModule,
        FormsModule,
        AppRoutingModule // Add AppRoutingModule to the imports array
    ],
    providers: [],
    bootstrap: [AppComponent]
})
export class AppModule { }
