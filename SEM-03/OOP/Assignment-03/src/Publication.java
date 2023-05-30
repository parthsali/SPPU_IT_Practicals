import java.util.Scanner;
public class Publication {
    String title;
    double price;
    int copies;
    static double totalPrice;
    Scanner sc = new Scanner(System.in);
    
    void getData(){
        System.out.print("Enter Title : ");
        title = sc.nextLine();

        System.out.print("Enter Price : ");
        price = sc.nextDouble();
        System.out.print("Enter Number of Copies : ");
        copies = sc.nextInt();
    }
    void saleCopy(){
        System.out.println("\nTotal Sell : " + (totalPrice));
    }
    void totalPublicationSell(){
        System.out.println("Total Publication Sell : " + totalPrice);
    }

}

