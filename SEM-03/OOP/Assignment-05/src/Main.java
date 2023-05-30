import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Bicycle b1 = new Bicycle();
        Bike b2 = new Bike();
        Car c1 = new Car();

       while(true){
           System.out.println("\nSelect");
           System.out.println("1.Change Gear");
           System.out.println("2.Speed Up");
           System.out.println("3.Apply Break");
           System.out.println("4.Display Speed and Gear");
           System.out.println("5.Exit\n");

           int choice;
           System.out.print("Enter Your Choice : ");
           choice = sc.nextInt();
           System.out.println("");
           switch (choice){
               case 1:
                   int tempGear;
                   System.out.print("Enter the Gear That You Want to Change to: ");
                   tempGear = sc.nextInt();
                   b1.changeGear(tempGear);
                   break;
               case 2:
                   int tempSpeed;
                   System.out.print("Enter The Value of Speed: ");
                   tempSpeed = sc.nextInt();
                   b1.speedUp(tempSpeed);
                   break;
               case 3:
                   int temp;
                   System.out.print("Enter The Value of Speed That You Want to Decrement: ");
                   temp = sc.nextInt();
                   b1.applyBreaks(temp);
                   break;
               case 4:
                   b1.display();
                   break;
               case 5:
                   System.out.println("Exiting The Program..");
                   System.exit(0);
           }
       }
    }
}