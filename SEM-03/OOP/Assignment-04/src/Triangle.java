public class Triangle extends Shape{
    
    @Override
    void getDim(){
        System.out.println("Enter Triangle's Dimension : ");
        System.out.print("Enter Base : ");
        base = sc.nextDouble();
        System.out.print("Enter Height : ");
        height = sc.nextDouble();
        System.out.println();
    }

    @Override
    void computArea(){
        System.out.println("Area of Triangle : " + (this.base*this.height)/2  + " sq. units "+ "\n\n" );
    }

}
