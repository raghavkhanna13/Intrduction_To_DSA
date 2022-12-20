import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    public void findCombinations(int arr[], boolean freq[], List<Integer> temp, List<List<Integer>> ans){
        if(temp.size() == arr.length){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i = 0; i < arr.length; i++){
            if(freq[i]) continue;
            if(i > 0 && arr[i - 1] == arr[i] && !freq[i - 1]) continue;
            freq[i]= true;
            temp.add(arr[i]);
            findCombinations( arr, freq, temp, ans);
            freq[i] = false;
            temp.remove(temp.size() - 1);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean freq[] = new boolean[nums.length];
        Arrays.sort(nums);
        findCombinations( nums,freq, new ArrayList<>(), ans);
        return ans;
    }
}