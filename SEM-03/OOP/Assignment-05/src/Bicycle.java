class Bicycle implements Vehicle{
    private int gear;
    private int speed;
    final int maxSpeed = 50;

    @Override
    public void changeGear(int a){
        if(a > 0){
            gear = a;
        }
        else{
            System.out.println("Gear cannot be Negative.");
        }

    }

    @Override
    public void applyBreaks(int a) {
        speed -= a;
    }

    @Override
    public void speedUp(int a){
        if(speed+a <= maxSpeed){
            speed += a;
        }
        else{
            System.out.println("Maximum Speed of Bicycle is " + maxSpeed);
        }

    }
    @Override
    public void display(){
        System.out.println("Speed of Bicycle : " + speed);
        System.out.println("Gear of Bicycle : " + gear);
    }

}
