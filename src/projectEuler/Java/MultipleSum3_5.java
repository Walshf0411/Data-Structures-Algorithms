package projectEuler.Java;

import java.io.*;
import java.util.*;
public class MultipleSum3_5{
    public static void main(String args []){
        Scanner sc= new Scanner(System.in);
        System.out.println("enter the upper limit for the sum");
        int n = sc.nextInt();
        long sum = 0;
        for (int i = 1; i < n; i++){
            if(i % 3 == 0 || i % 5 == 0){
                sum += i;
            }
            
        }
        System.out.println(sum);
        sc.close();
    }
}