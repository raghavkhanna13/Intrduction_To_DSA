import java.util.ArrayList;
import java.util.Scanner;

public class printSubsequenceTillSum {

    static void printSub(int index, int arr[], ArrayList<Integer> res, int s, int sum) {
        if (index == arr.length) {

            if (s == sum){
                System.out.println(res);
            }
            return;
        }

        res.add(arr[index]);
        sum += arr[index];
        printSub(index + 1, arr, res, s, sum);

        res.remove(res.size() - 1);
        sum -= arr[index];
        printSub(index + 1, arr, res, s, sum);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        
        System.out.println("Enter array elements");
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter sum: ");
        int s = sc.nextInt();
        sc.close();

        ArrayList<Integer> res = new ArrayList<>();
        printSub(0, arr, res, s, 0);
    }
}
