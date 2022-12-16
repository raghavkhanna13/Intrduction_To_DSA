import java.util.Scanner;

public class countSubsequenceTillSum {

    static int countSub(int index, int sum, int s, int arr[]) {
        if (index == arr.length) {
            if (sum == s)
                return 1;
            else
                return 0;
        }

        sum += arr[index];
        int left = countSub(index + 1, sum, s, arr);

        sum -= arr[index];
        int right = countSub(index + 1, sum, s, arr);

        return left + right;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Size: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter Sum = ");
        int s = sc.nextInt();
        sc.close();

        System.out.println();

        System.out.println(countSub(0, 0, s, arr));
    }
}
