class Complex{
    double real;
    double img;

    public Complex(){
        this(0, 0 );
    }
    public Complex(double real , double img){
        this.real = real;
        this.img = img;
    }

    public Complex addComplexNums(Complex b) {
        Complex c = new Complex();
        c.real = this.real + b.real;
        c.img = this.img + b.img;
        return c;
    }

    public Complex subComplexNums(Complex b){
        Complex c = new Complex();
        c.real = this.real - b.real;
        c.img = this.img - b.img;
        return c;
    }
    public Complex mulComplexNum(Complex b){
        Complex c = new Complex();
        c.real = this.real*b.real - this.img*b.img;
        c.img = this.real*b.img + this.img*b.real;
        return c;
    }

    public Complex divComplexNums(Complex b){
        Complex c = new Complex();
        c.real = (this.real*b.real + this.img*b.img)/(b.real*b.real + b.img*b.img);
        c.img = (this.img*b.real - this.real)/(b.real*b.real + b.img*b.img);
        return c;
    }

    public void displayComplexNum(){
        System.out.println();
        if(this.real == 0 && this.img == 0){
            System.out.println("Final Complex Number is : " + 0);
        }
        else if(this.real == 0 && this.img != 0){
            System.out.println("Final Complex Number is : " + this.img + "i");
        }
        else if(this.real != 0 && this.img == 0){
            System.out.println("Final Complex Number is : " + this.real);
        }
        else if(this.img < 0){
            System.out.println("Final Complex Number is : " + this.real + this.img + "i");
        }
        else{
            System.out.println("Final Complex Number is : " + this.real + "+" + this.img + "i");
        }
        System.out.println();
    }


}
