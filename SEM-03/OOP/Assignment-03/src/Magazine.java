import java.util.Scanner;
public class Magazine extends Publication{
    int orderQty;
    String currentIssue;
    public double MagSell;
    public static double totalMagSell;
    Scanner sc = new Scanner(System.in);

//    int getOrderQty(){
//        return this.orderQty;
//    }
//    void setOrderQty(int orderQty){
//        this.orderQty = orderQty;
//    }
//    void getMagazineData(){
//        System.out.print("Enter Order  : ");
//        orderQty = sc.nextInt();
//    }

//    void receiveIssue(String newIssue) {
//        currentIssue = newIssue;
//    }


    @Override
    void saleCopy(){
        MagSell = (this.copies * this.price);
        Magazine.totalMagSell += MagSell;
        Publication.totalPrice += totalMagSell;
        System.out.print("\n");
        System.out.println("Ordered Magazine :" + this.title);
        System.out.println("Total Amount : " + MagSell);
        System.out.print("\n");

    }
    void totalMagSell(){
        System.out.println("Total Magazine Sell : " + totalMagSell);
    }
}
