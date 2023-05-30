public class CarFactory {

    public static Car constructCar(model name){
        Car car = null;

        switch (name) {
            case SEDAN:
                car = new Sedan();
                break;
            case SUV:
                car = new SUV();
                break;
            case HATCHBACK:
                car = new HatchBack();
                break;
            default:
                break;
        }
        return car;

    }
}
