import java.util.Scanner;
enum model{
    SEDAN,
    SUV,
    HATCHBACK
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Car car;
        int count = 0;

        while(true){
            System.out.println("Welcome.");
            if(count == 0){
                System.out.print("Enter Car You Want to Construct : ");
                count++;
            }
            else{
                System.out.print("Enter Car You Want to Construct (Enter 'exit' to exit from program) : ");
            }


            String carName = sc.next().toUpperCase();
            System.out.println();

            if(carName.equals("EXIT")){
                System.out.println("Exiting the Program...");
                break;
            }
            car = CarFactory.constructCar(model.valueOf(carName));
            car.construct();
        }
    }
}