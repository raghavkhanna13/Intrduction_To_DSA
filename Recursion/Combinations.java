import java.util.ArrayList;
import java.util.List;

class Solution {
    public void findCombinations(int index, int arr[], int n, int k, List<List<Integer>> ans, List<Integer> temp){
        if(index == n){
            if(temp.size() == k){
            ans.add(new ArrayList<>(temp));
            }
            return;
        }

        temp.add(arr[index]);
        findCombinations(index + 1, arr, n, k, ans, temp);

        temp.remove(temp.size() - 1);
        findCombinations(index + 1, arr, n, k, ans, temp);
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = i + 1;
        }
        findCombinations(0, arr, n, k, ans, new ArrayList<>());

        return ans;
    }
}