import java.util.Scanner;

public class bubbleSort {

    static void Sort(int arr[], int n){
        for(int i = 1; i < n; i++){
            boolean flag = false;
            for(int j = 0; j < n -i; j++){
                if(arr[j] > arr[j+1]){
                    //Logic Of Xor Operator 
                    arr[j] = arr[j] ^ arr[j+1];
                    arr[j+1] = arr[j] ^ arr[j+1];
                    arr[j] = arr[j] ^ arr[j+1];
                    flag = true;
                }
            }

            if(flag == false){
                break;
            }
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
