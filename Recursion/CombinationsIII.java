import java.util.*;
class Solution {

    public void findCombinations(int index, int k, int target, List<List<Integer>> ans, List<Integer> temp){
        if(k == 0){
            if(target == 0){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }
        // if( target > 0) return;
        if(index == 10) return;

        temp.add(index);
        findCombinations(index + 1, k - 1, target - index, ans, temp);
        temp.remove(temp.size() - 1);

        findCombinations(index + 1, k, target, ans, temp);
    }

        

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombinations(1, k, n, ans, new ArrayList<>());
        return ans;
    }
}