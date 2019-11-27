import java.util.Scanner;

class GSSArray{
    private int array[];
    private int size;
    private int elements = 0;
    
    Scanner S = new Scanner(System.in);

    GSSArray(){
        System.out.println("Enter the initial size of the array:");
        size = S.nextInt();

        array = new int[size];
    }

    private void increaseSize(){
        size = size*2;
        int temp[] = new int[size];

        for (int i = 0; i < elements; i++) {
            temp[i] = array[i];
        }

        array = temp;
    }

    void displaySize() {
        System.out.println(size);
    }

     void insert(int x){
        
        if (elements == size-1) {
            increaseSize();
        }

        for (int i = 0; i <= elements; i++) {
            if (array[i] > x) {
                continue;
            }
            else{
                
                for (int j = elements; j >= i; --j ) {
                    array[j+1] = array[j];
                }
                array[i] = x;
                elements++;
                break;
            }
        }

        
    }

    void display(){
        System.out.println("\n----------------\n   Your Array:\n");
        for (int i = 0; i < elements; i++) {
            System.out.println("\t"+array[i]);
        }
        System.out.println("\n----------------\n");
    }

    boolean delete(int x){
        for (int i = 0; i < elements; i++) {
            if(array[i] == x){
                int j;
                for (j = i; j < elements; j++) {
                    array[j] = array[j+1];
                }
                array[j] = 0;
                --elements;

                return true;
            }
            else{
                continue;
            }
        }
        return false;
    }

}

class GSSArrayDemo{
    public static void main(String[] args) {

        GSSArray arr = new GSSArray();

        Scanner S = new Scanner(System.in);
    

        int data;
        boolean flag = true;
        System.out.println("Enter +111111 To insert.\nEnter -111111 to delete.\nEnter +555555 to Display.\nEnter 0 to exit.");

        while (true) {
            data = S.nextInt();

            if(data == -111111){
                System.out.println("Enter Element You Want to delete");
                flag = false;
                continue;
            }else if(data == +111111){
                System.out.println("Enter Your Elements");
                flag = true;
                continue;
            }else if(data == 0){
                System.out.println("Thank You!");
                break;
            }
            else if(data == +555555){
                arr.display();
            }
                

            if(flag == true){
                arr.insert(data);
            }
            else{
                arr.delete(data);
            }
        }

        
    }

}