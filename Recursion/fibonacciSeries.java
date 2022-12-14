import java.util.Scanner;

public class fibonacciSeries {

    static int fib(int n){
        if(n <= 1)
            return n;
        
        return fib(n-1) + fib(n-2);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        sc.close();

        System.out.println("Result = " + fib(n));
    }
}
/*
 Time complexity = O(2^n) exponential
 Space complexity = O(n)
 */
