import java.util.Scanner;

public class insertionSort {

    static void Sort(int arr[], int n){
        for(int i = 1; i < n; i++){
            int temp = arr[i];
            int j = i - 1;
            for(; j >= 0; j--){
                if(arr[j] > temp){
                    //shift
                    arr[j+1] = arr[j];
                }
                else{
                    break;
                }

                
            }
            arr[j+1] = temp;

        }

        /*
            Time Complexity = O(n^2)
            Space Complexity = O(1);
        */
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];

        for(int i = 0; i< n; i++){
            arr[i] = sc.nextInt();
        }

        Sort(arr, n);

        //printing the array
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+" ");
        }
    }
}
