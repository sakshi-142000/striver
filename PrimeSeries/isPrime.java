//package striver;

public class isPrime {

    public static void main(String[] args){
        int n=15;
        System.out.println(isPrimeFunc(n)); 
        System.out.println(i);
    }

    static int i =2;

    static int isPrimeFunc(int n){
        if (n==0 || n==1) {
            // System.out.println("condition 1"+ i);
            return 0;
            
        }
        else if (n==i) {
            // System.out.println("condition 3"+ i);
            return 1;
            
        }
        else if (n%i == 0) {
            // System.out.println("condition 2"+ i);
            return 0;
            
        }
        
        i++;
        return isPrimeFunc(n);
    }
     
}



