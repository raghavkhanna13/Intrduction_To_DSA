import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {

    void findCombinations(int index, int arr[], ArrayList<Integer> temp, List<List<Integer>> ans){
        if(index == arr.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        
        //picking the element
        temp.add(arr[index]);
        findCombinations(index + 1, arr, temp, ans);
        
        //not picking the element
        temp.remove(temp.size() - 1);
        findCombinations(index + 1, arr, temp, ans);
        
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombinations(0, nums, new ArrayList<>(), ans);
        //for sorting list of list we need to do this
        Collections.sort(ans,new Comparator<List<Integer>>(){
            public int compare(List<Integer> p,List<Integer> q)
            {   
                int oneSize = p.size();
                int twoSize = q.size();

                for(int i = 0; i < Math.min(oneSize,twoSize); i++){
                if(i == oneSize || i == twoSize)
                return oneSize - twoSize;

                int elementOne = p.get(i);
                int elementTwo = q.get(i);
                
                if(elementOne == elementTwo)
                   continue;
                   
                return Integer.compare(elementOne, elementTwo);
                }
                return p.size()-q.size();
            }
        });
        return ans;
    }
}
