import java.util.HashMap;
import java.util.Arrays;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = {2, 7, 11, 15};
        System.out.println(Arrays.toString(sol.twoSum(arr, 9)));
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> memo = new HashMap<Integer,Integer>();
        int[] result = new int[2];

        for(int i=0;i<nums.length;i++){
            if(memo.containsKey(target-nums[i])){
                result[0] = memo.get(target-nums[i]);
                result[1] = i;
                break;
            }

            memo.put(nums[i], i);
        }

        return result;
    }
}
