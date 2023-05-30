import java.util.ArrayList;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean flag = true;
        while(flag){
            System.out.println("a. Integer Array.");
            System.out.println("b. String Array.");
            System.out.println("c. Exit.");
            System.out.println();

            System.out.print("Enter Your Choice : ");
            char choice = sc.next().charAt(0);
            System.out.println();
            switch (choice){
                case 'a':
                    Generic<Integer> intArray = new Generic<>();
                    intArray.getData();
                    intArray.printEvenNums();
                    intArray.printOddNums();
                    intArray.printPrimeNums();
                    System.out.println();
                    break;
                case 'b':
                    Generic<String> stringArray = new Generic<>();
                    stringArray.getData();
                    stringArray.printPalindromes();
                    System.out.println();
                    break;
                case 'c':
                    flag = false;
                    System.out.println("Exiting the program..");
                    break;
            }
        }


    }
}