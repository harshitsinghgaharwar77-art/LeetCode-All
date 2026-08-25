class Solution {
    public void solve(int[] candidates, int target, int idx, List<List<Integer>> ans, List<Integer> output){
        // base case
        if(target == 0){
            ans.add(new ArrayList<>(output));
            return;
        }

        if(idx >= candidates.length || target < 0){
            return;
        }

        // include
        output.add(candidates[idx]);
        solve(candidates, target-candidates[idx], idx+1, ans, output);
        // backtrack
        output.remove(output.size()-1);
        // make sure no duplicates exist
        while(idx+1 < candidates.length && candidates[idx] == candidates[idx+1]){
            idx++;
        }
        // exclude
        solve(candidates, target, idx+1, ans, output);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();

        int idx= 0 ;
        solve(candidates, target, idx, ans, output);
        return ans;
    }
}