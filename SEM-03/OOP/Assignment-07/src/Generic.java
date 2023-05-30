import java.awt.image.AreaAveragingScaleFilter;
import java.util.ArrayList;
import java.util.Scanner;

public class Generic <T> {
    Scanner sc = new Scanner(System.in);
    ArrayList<T> array = new ArrayList<T>();


    public void getData() {
        System.out.print("Enter Number of Elements You Want to Add in Array : ");
        int n = sc.nextInt();

        System.out.print("Enter Array Elements : ");
        for (int i = 0; i < n; i++) {
            T temp = (T) sc.next();
            array.add(temp);
        }
        displayArray();

    }

    public void displayArray() {
        System.out.println();
        System.out.println("Array : " + array);
        System.out.println();
    }

    private boolean isEven(int num) {
        return num % 2 == 0;
    }

    private boolean isOdd(int num) {
        return num % 2 != 0;
    }

    private boolean isPrime(int num) {
        int temp = 0;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                temp++;
            }
        }
        if (temp == 0) {
            return true;
        } else {
            return false;
        }

    }

    private boolean isPalindrome(String str) {
        String reverseStr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reverseStr += str.charAt(i);
        }
        if (str.equals(reverseStr)) {
            return true;
        } else {
            return false;
        }
    }

    public void printEvenNums() {
        System.out.println("Even Numbers Are : ");
        for (int i = 0; i < array.size(); i++) {
            int num = Integer.parseInt((String)array.get(i)) ;
            if (isEven(num)) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }

    public void printOddNums() {
        System.out.println("Odd Numbers Are : ");
        for (int i = 0; i < array.size(); i++) {
            int num = Integer.parseInt((String) array.get(i));
            if (isOdd(num)) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }

    public void printPrimeNums() {
        System.out.println("Prime Numbers Are : ");
        for (int i = 0; i < array.size(); i++) {
            int num = Integer.parseInt((String) array.get(i));
            if (isPrime(num)) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }

    public void printPalindromes() {
        System.out.println("Palindromes are : ");
        for (int i = 0; i < array.size(); i++) {
            String temp = (String) array.get(i);
            if (isPalindrome(temp)) {
                System.out.print(temp + " ");
            }
        }
        System.out.println();
    }
}