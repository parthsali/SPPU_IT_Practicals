import java.util.Scanner;
import java.lang.Math;

public class Employee {
    String employeeName;
    int employeeID;
    String status;
    String employeeMail;
    String employeeAd;
    int employeeMob;
    double basicPay;
    Scanner sc = new Scanner(System.in);

    void getData(){
        System.out.print("Name: ");
        employeeName = sc.nextLine();
        System.out.print("ID: ");
        employeeID = sc.nextInt();
        System.out.print("Mail: ");
        employeeMail = sc.nextLine();
        System.out.print("Address: ");
        employeeAd = sc.nextLine();
        System.out.print("Mobile Number: ");
        employeeMob = sc.nextInt();
    }

    void displayData(){
        System.out.println("----------Personal Info----------");
        System.out.println("Name            : " + this.employeeName);
        System.out.println("ID              : " + this.employeeID);
        System.out.println("Status          : " + this.status);
        System.out.println("Mail            : " + this.employeeMail);
        System.out.println("Address         : " + this.employeeAd);
        System.out.println("Mobile No       : " + this.employeeMob);
        System.out.print("\n");
    }

}
