//package striver;

import java.util.Arrays;
import java.util.Scanner;

public class hashing {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int[] arr = new int[100000000];
        
        System.out.println("Enter the size of array");
        int n = scan.nextInt();
        int max=0;
        System.out.println("Enter the array elements");
        for(int i=0;i<n;++i){
            arr[i]=scan.nextInt();
            if(max<arr[i]) max=arr[i];
        }
        //pre computing
        int[] hashArray = new int[max+1];
        for(int i=0;i<n;++i){
            hashArray[arr[i]]+=1;
        }
        System.out.println("queries begin");
        int q = scan.nextInt();// number of queries
        while(q>0){
            int num = scan.nextInt();
            System.out.printf("count of %d is %d ", num, hashArray[num]);// fetching the count of number from the pre computed hash array
            q-=1;
        }

        // for(int i=0;i<n;++i){
        //     System.out.println(arr[i]);
        // }

        //System.out.println(Arrays.toString(arr));
    }
}
