import java.util.Scanner;
public class Book extends Publication{
    String author;
    public double bookSell;
    public static double totalBookSell;
    public Scanner sc = new Scanner(System.in);

    void getAuthor(){
        System.out.print("Enter Author's Name : ");
        author = sc.nextLine();
    }
    void getBookData(){
        getData();
        getAuthor();
    }
    void orderCopies(){
        System.out.print("Order Copies : ");
        int newCopies = sc.nextInt();
        this.copies = newCopies + this.copies;
    }


    @Override
    void saleCopy(){
        bookSell = (this.copies * this.price);
        Book.totalBookSell += bookSell;
        Publication.totalPrice += totalBookSell;
        System.out.print("\n");
        System.out.println("Ordered Book : " + this.title);
        System.out.println("Total Amount : " + bookSell);
        System.out.print("\n");
    }

    void totalBookSell(){

        System.out.println("Total Book Sell : " + totalBookSell);
    }


}
