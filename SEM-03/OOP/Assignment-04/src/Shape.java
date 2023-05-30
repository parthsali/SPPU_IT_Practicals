import java.util.Scanner;

abstract class Shape {
    protected double base;
    protected double height;
    Scanner sc = new Scanner(System.in);

    Shape(){
        base = 0;
        height = 0;
    }
    abstract void getDim();

    abstract void computArea();

}
