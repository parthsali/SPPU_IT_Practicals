import java.util.Scanner;

public class SUV implements Car{
    private String carName = "SUV";
    private String carMaterial = "";
    private String engine = "";
    public String getCarName(){
        return carName;
    }
    Scanner sc= new Scanner(System.in);
    @Override
    public void construct() {
        System.out.println("Constructing SUV...");
        System.out.println();
        constructEngine();
        carFrame();
        displayInfo();
    }
    private void constructEngine(){
        System.out.println("Which Engine You Want to use.");
        System.out.println("1. Ferrari 3.9-litre twin-turbo V8");
        System.out.println("2. BMW M 3.2-litre straight-six");
        System.out.println("3. Ford 1.0-litre EcoBoost");
        System.out.println();
        System.out.print("Enter Your Choice : ");

        int choice = sc.nextInt();
        switch (choice){
            case 1:
                engine = "Ferrari 3.9-litre twin-turbo V8";
                break;
            case 2:
                engine = "BMW M 3.2-litre straight-six";
                break;
            case 3:
                engine = "Ford 1.0-litre EcoBoost";
                break;
            default:
                System.out.println("Enter Valid Choice..");
                break;
        }
        System.out.println(engine + " engine added to SUV.");
        System.out.println();
    }
    private void carFrame(){
        System.out.println("Which material you want use for Frame.");
        System.out.println("1. Steel");
        System.out.println("2. Carbon Fibre");
        System.out.println();
        System.out.print("Enter Your Choice : ");

        int choice = sc.nextInt();
        switch (choice){
            case 1:
                carMaterial = "Steel";
                break;
            case 2:
                carMaterial = "Carbon Fibre";
                break;
            default:
                System.out.println("Enter Valid Choice..");
                break;
        }
        System.out.println("Car Material : " + carMaterial);
        System.out.println();
    }
    private void displayInfo(){
        System.out.println("----Car Details----");
        System.out.println("Car Name : " + getCarName());
        System.out.println("Car Engine : " + engine);
        System.out.println("Car Frame Material : " + carMaterial);
        System.out.println();
    }
}
