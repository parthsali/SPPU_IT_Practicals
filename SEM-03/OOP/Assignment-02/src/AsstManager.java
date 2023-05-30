import java.util.Scanner;

public class AsstManager extends Employee {
        Scanner sc = new Scanner(System.in);
        double da;
        double hra;
        double pf;
        double clubFee;
        double grossSalary;
        double netSalary;

        public AsstManager(){
            System.out.println("-----Programmer`s Data-----");
            getData();
            getBasicPay();
            super.status = "Asst. Manager";
            displayData();
            generateSlip();
        }
        void getBasicPay(){
            System.out.print("Basic Salary : ");
            System.out.println("\n");
            basicPay = sc.nextDouble();
            da = 0.97*basicPay;
            hra = 0.10*basicPay;
            pf = 0.12*basicPay;
            clubFee = 0.001*basicPay;
            grossSalary = basicPay + da + hra;
            netSalary = grossSalary - pf - clubFee;
        }
        void generateSlip(){
            System.out.println("-----------Pay Slip-----------");
            System.out.println("Basic Pay       : " + this.basicPay);
            System.out.println("DA              : " + this.da);
            System.out.println("HRA             : " + this.hra);
            System.out.println("PF              : " + this.pf);
            System.out.println("Gross Salary    : " + this.grossSalary);
            System.out.println("Net Salary      : " + this.netSalary);
            System.out.print("\n\n");
        }



}
