class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        backtrack(nums, new ArrayList<>(), used, res);
        return res;
    }
    private void backtrack(int[] nums, List<Integer> temp, boolean[] used, List<List<Integer>> res){
        // base case
        if(temp.size() == nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }

        for(int i = 0; i < nums.length; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            temp.add(nums[i]);

            // recursive calls
            backtrack(nums,temp,used,res);
            // backtrack
            temp.remove(temp.size() - 1);
            used[i] = false;
        }
    }
}