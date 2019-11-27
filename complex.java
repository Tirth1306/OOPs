class complex {
    private float real;
    private float imaginary;

    complex(){
        real = 0.0f;
        imaginary = 0.0f;
    }

    float getReal(){
        return real;
    }

    float getImaginary(){
        return imaginary;
    }

    void setReal(float x){
        real = x;
    }

    void setImaginary(float x){
        imaginary = x;
    }



    complex Add(complex b){
        complex add = new complex();
        add.setImaginary(b.getImaginary() + imaginary);
        add.setReal(b.getReal() + real);
        return add;
    }

    complex Subtract(complex b){
        complex sub = new complex();
        sub.setImaginary(imaginary - b.getImaginary());
        sub.setReal(real - b.getReal());
        return sub;
    }

    void display(){
        System.out.print("" + real + " + " + imaginary + "i ");
    }
}

