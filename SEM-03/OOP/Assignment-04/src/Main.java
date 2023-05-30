import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Triangle t = new Triangle();
        Rectangle r = new Rectangle();

        while (true){
            System.out.println("-----Area Calculator-----\n");
            System.out.println("Enter");
            System.out.println("1.Calculate Area of Triangle.");
            System.out.println("2.Calculate Area of Reactangle.");
            System.out.println("3.Exit.\n");

            int choice;
            System.out.print("Enter Your choice : ");
            choice = sc.nextInt();
            System.out.println();

            switch (choice){
                case 1 :
                    t.getDim();
                    t.computArea();
                    break;
                case 2 :
                    r.getDim();
                    r.computArea();
                    break;
                case 3 :
                    System.out.println("Exiting The Program..");
                    System.exit(0);
                default:
                    System.out.println("Invalid Input..\n\n");
            }
        }


    }
}