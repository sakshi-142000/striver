class PrePostDemo {
    public static void main(String[] args){

        
        // i++;
        // System.out.printf("post fix i++ %d", i);

        // ++i;

        // System.out.printf("pre fix i++ %d", i);


        // System.out.printf("pre fix i++ %d", i);

        
        int i = 3;
        int j = i++ + i; //7
        System.out.printf("i = %d, j = %d \n", i, j);

        int k = ++i + i;//10
        System.out.printf("i = %d, k = %d \n", i, k);      






        // int i = 3;
        // i++;
        // System.out.println(i);  // // prints 4
        // ++i;			          
        // System.out.println(i);  // // prints 5
        // System.out.println(++i);  // // prints 6
     
        // System.out.println(i++);    // // prints 6
       
        // System.out.println(i);  // // prints 7
    }
}