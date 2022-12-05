class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[start]){
                //left halve is sorted
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            
            else{
                //right halve is sorted
                if(target <= nums[end] && target > nums[mid]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                } 
            }
        }
        return -1;
    }
}