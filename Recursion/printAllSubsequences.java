import java.util.ArrayList;
import java.util.Scanner;

public class printAllSubsequences {

    static void printAll(int index, ArrayList<Integer> res, int arr[], int n) {
        if (index == n) {
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) {
                    System.out.print(res.get(i) + " ");
                }
            }
            if (res.size() == 0) {
                System.out.print("{}");
            }
            System.out.println();
            return;
        }

        // by taking the value from arr and going forward
        res.add(arr[index]);
        printAll(index + 1, res, arr, n);

        // by taking the value from arr and going forward
        res.remove(res.size() - 1);
        printAll(index + 1, res, arr, n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        ArrayList<Integer> res = new ArrayList<>();

        printAll(0, res, arr, n);
        sc.close();
    }
}
/*
 Time Complexity = O(2^n)
 Space Complexity = O(n);
 */