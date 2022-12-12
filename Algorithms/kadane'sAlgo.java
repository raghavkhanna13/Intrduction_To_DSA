class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        
        //Kadane's algorithm => O(n)
        int sum = 0;
        int maxi = arr[0];
        
        for(int i = 0; i < n; i++ ){
            //step 1
            sum += arr[i];
            
            //step 2
            maxi = (sum > maxi) ? sum : maxi;
            
            //step3
            if(sum < 0)
                sum = 0;
        }
        
        return maxi;
    }
    
}