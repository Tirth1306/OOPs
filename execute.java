class execute {
    public static void main(String[] args) {
        complex a = new complex();
        complex b = new complex();

        a.setReal(2.0f);
        b.setReal(3.5f);
        a.setImaginary(9.8f);
        b.setImaginary(10.3f);

        complex add;
        complex sub;

        add = a.Add(b);
        sub = a.Subtract(b);

        System.out.print("\nSum of (");
        a.display();
        System.out.print("& ");
        b.display();
        System.out.print("is (");
        add.display();

        System.out.print("\n\nSubtraction of (");
        a.display();
        System.out.print("& ");
        b.display();
        System.out.print("is ");
        sub.display();
    }

}