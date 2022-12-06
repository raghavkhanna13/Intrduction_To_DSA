import java.util.* ; 
public class selectionSort {
	public static void Sort(int arr[], int n) {
		// Write your code here
        for(int i = 0; i < n - 1; i++){
            int minIndex = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }
            
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
	}

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();


        Sort(arr, n);
        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
    }
}