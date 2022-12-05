class Solution {
    public int mySqrt(int x) {
        long start = 0;
        long end = x;
        long ans = 0;
        while(start <= end){
            long mid = (start + end)/2;
            long square = mid*mid;
            if(square > x){
                end = mid - 1;
            }
            else if(square < x){
                ans = mid;
                start = mid + 1;
            }
            else{
                return (int)mid;
            }
        }
        
        return (int)ans;
        
    }
}
//implemented using binary search technique