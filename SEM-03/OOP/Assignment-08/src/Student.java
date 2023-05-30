import java.util.Scanner;

public class Student {
    private int student_id;
    private String student_name;
    private int roll_num;
    private int class_num;
    private float marks;
    private String address;
    public Scanner sc = new Scanner(System.in);

    Student(){
        this( "", 0, 0, 0, 0, "");
    }
    Student(String student_name, int student_id, int roll_num, int class_num, int marks, String address){
        this.student_id = student_id;
        this.student_name = student_name;
        this.roll_num = roll_num;
        this.class_num = class_num;
        this.marks = marks;
        this.address = address;


    }

    public void getData(){
        System.out.println("");
        System.out.print("Enter Your Name : ");
        this.student_name = sc.nextLine();
        System.out.print("Enter Your ID : ");
        this.student_id = sc.nextInt();
        System.out.print("Enter Your Roll No : ");
        this.roll_num = sc.nextInt();
        System.out.print("Enter Your Class Number : ");
        this.class_num = sc.nextInt();
        System.out.print("Enter Your Marks : ");
        this.marks = sc.nextFloat();
        System.out.print("Enter Your Address : ");
        this.address = sc.nextLine();
    }

    public void displayData(){
        System.out.println();
        System.out.println("Student Name : " + this.student_name);
        System.out.println("Student ID : " + this.student_id);
        System.out.println("Student Roll No : " + this.roll_num);
        System.out.println("Student Class Number : " + this.class_num);
        System.out.println("Student Marks : " + this.marks);
        System.out.println("Student Address : " + this.address);
        System.out.println();
    }
}
