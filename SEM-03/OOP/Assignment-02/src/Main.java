// Assignment-02 : Polymorphism.

// Problem Statement : Identify commonalities and differences between Publication, Book and Magazine classes. 
// Title, Price, Copies are common instance variables and saleCopy is common method. The differences are, Bookclass 
// has author and order Copies(). Magazine Class has methods orderQty, Currentissue, receiveissue().Write a program to 
// find how many copies of the given books are ordered and display total sale of publication.

// Program by : Parth Sali.


import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("Generate Pay Slip for Employee\n");
            System.out.println("1 : Programmer");
            System.out.println("2 : Project Manager");
            System.out.println("3 : Asst. Manager");
            System.out.println("4 : Team Leader");
            System.out.println("5 : Exit");
            System.out.print("\n");

            int ope;
            System.out.print("Enter Your Choice : ");
            ope = sc.nextInt();
            System.out.print("\n");

            switch (ope){
                case 1 :
                    Programmer p = new Programmer();
                    break;
                case 2 :
                    ProjectManager m = new ProjectManager();
                    break;
                case 3 :
                    AsstManager a = new AsstManager();
                    break;
                case 4 :
                    TeamLeader l = new TeamLeader();
                    break;
                case 5 :
                    System.exit(0);
                default:
                    System.out.println("Enter Valid Info..");
            }


        }


    }

}
