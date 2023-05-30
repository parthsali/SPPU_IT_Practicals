import java.util.Scanner;

public class TeamLeader extends Employee {
    Scanner sc = new Scanner(System.in);


    double da;
    double hra;
    double pf;
    double clubFee;
    double grossSalary;
    double netSalary;

    public TeamLeader(){
        System.out.println("Enter Team Leader's Data");
        getData();
        getBasicPay();
        status = "Team Leader";
        displayData();
        generateSlip();
    }
    void getBasicPay(){
        System.out.print("Basic Salary : ");
        basicPay = sc.nextDouble();
        System.out.println("\n");
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
