public class Rectangle extends Shape{
    @Override
    public void getDim(){
        System.out.println("Enter Rectangle's Dimension : ");
        System.out.print("Enter Width : ");
        base = sc.nextDouble();
        System.out.print("Enter Height : ");
        height = sc.nextDouble();
        System.out.println();
    }

    @Override
    void computArea(){
        System.out.println("Area of Rectangle : " + this.base*this.height + " sq. units " + "\n\n");
    }


}
