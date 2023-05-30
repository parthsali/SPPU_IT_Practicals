// Assignment-01 : Classes and Object.

// Problem Statement : Design a class ‘Complex’with data members for real and imaginary part.
// Provide default and Parameterized constructors. Write a program to perform arithmetic 
// operations of two complex numbers.

// Program by : Parth Sali.

import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void takeInput(Complex a, Complex b){
        System.out.println("Enter ");
        System.out.print("Real Part of First Complex Number : ");
        a.real = sc.nextDouble();
        System.out.print("Imaginary Part of First Complex Number : ");
        a.img = sc.nextDouble();
        System.out.print("Real Part of Second Complex Number : ");
        b.real = sc.nextDouble();
        System.out.print("Imaginary Part of Second Complex Number : ");
        b.img = sc.nextDouble();
        System.out.println();
    }
    public static void main(String[] args) {

        while(true){
            System.out.println("Complex Number Calculator.");
            System.out.println("1. Addition.");
            System.out.println("2. Subtraction.");
            System.out.println("3. Multiplication.");
            System.out.println("4. Division.");
            System.out.println("5. Exit.");
            System.out.println();

            System.out.print("Enter Your Choice: ");
            int choice = sc.nextInt();

            switch (choice){
                case 1 :
                    Complex a1 = new Complex();
                    Complex b1 = new Complex();
                    takeInput(a1,b1);
                    Complex c = a1.addComplexNums(b1);
                    c.displayComplexNum();
                    break;
                case 2:
                    Complex a2 = new Complex();
                    Complex b2 = new Complex();
                    takeInput(a2, b2);
                    Complex c2= a2.subComplexNums(b2);
                    c2.displayComplexNum();
                    break;
                case 3:
                    Complex a3 = new Complex();
                    Complex b3 = new Complex();
                    takeInput(a3, b3);
                    Complex c3 = a3.mulComplexNum(b3);
                    c3.displayComplexNum();
                    break;
                case 4:
                    Complex a4 = new Complex();
                    Complex b4 = new Complex();
                    takeInput(a4, b4);
                    Complex c4 = a4.divComplexNums(b4);
                    c4.displayComplexNum();
                    break;
                case 5:
                    System.exit(0);
            }


        }

    }
}
