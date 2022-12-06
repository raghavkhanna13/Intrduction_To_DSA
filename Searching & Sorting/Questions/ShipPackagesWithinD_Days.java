class Solution {
    
    boolean isPossible(int[] weights, int days, int mid){
        int weightSum = 0;
        int daysCount = 1;
        for(int i = 0; i < weights.length; i++){
            if(weightSum + weights[i] <= mid){
                weightSum += weights[i];
            }
            else{
                daysCount++;
                if(daysCount > days || weights[i] > mid){
                    return false;
                }
                weightSum = weights[i];
            }
        }
        return true;
    }
    public int shipWithinDays(int[] weights, int days) {
        int start = 0;
        int sum = 0;
        for(int i = 0; i < weights.length; i++){
            sum += weights[i];
        }
        int ans = -1;
        int end = sum;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if (isPossible(weights, days, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return ans;
    }
}

//implemented using binary search technique