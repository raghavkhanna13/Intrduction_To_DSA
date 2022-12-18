import java.util.Scanner;

public class power{

    public static double myPow(double x, int n){
        if(n<0){
            return 1/(myPow(x,-(n+1))*x);
        }
		if (n == 0) {
			return 1;
		} else if (n % 2 == 0) {
			double ans = myPow(x, n / 2);
            return ans * ans;
		} else {
			return x * myPow(x, n - 1);
		}
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        int n = sc.nextInt();
        sc.close();

        System.out.println(myPow(x, n));
    }
}