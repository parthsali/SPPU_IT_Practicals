
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Book b = new Book();
        Magazine m = new Magazine();
        Publication p = new Publication();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("Enter");
            System.out.println("1.Order Book");
            System.out.println("2.Order Magazine");
            System.out.println("3.Total Book Sell");
            System.out.println("4.Total Magazine Sell");
            System.out.println("5.Total Publication Sell");
            System.out.println("6.Exit\n");

            System.out.print("Enter Your Choice : ");
            int choice = sc.nextInt();
            System.out.print("\n");
            switch (choice){
                case 1:

                    b.getBookData();
                    b.saleCopy();
                    break;
                case 2:

                    m.getData();
                    m.saleCopy();
                    break;

                case 3:
                    b.totalBookSell();
                    break;

                case 4:
                    m.totalMagSell();
                    break;

                case 5:
                    p.saleCopy();

                    break;

                case 6:
                    System.out.println("Exiting The Program..");
                    System.exit(0);
                default:
                    System.out.println("Please Enter Valid Input..");

            }
        }
    }
}