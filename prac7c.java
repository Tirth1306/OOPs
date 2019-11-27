class prac7c {
    public static void main(String[] args) {
     
     
     String str="Welcome to Nirma";
     String[] a=str.split(" ");
     String reverse=new String();

     for(int i=0;i<a.length;i++)
     {
       
       for(int j=a[i].length()-1;j>=0;j--)
       {
         reverse=reverse+a[i].charAt(j);
       }

       reverse+=" ";
       
     }
    
     System.out.print(reverse);
    }
   }
   
   