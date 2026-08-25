class Solution {

    public void solve(int[] candidates, int target, int idx,
                      int k, List<List<Integer>> ans,
                      List<Integer> output) {

        // Target reached
        if (target == 0) {
            if (output.size() == k) {
                ans.add(new ArrayList<>(output));
            }
            return;
        }

        // Invalid case
        if (target < 0 || idx >= candidates.length) {
            return;
        }

        // Too many numbers selected
        if (output.size() >= k) {
            return;
        }

        // INCLUDE
        output.add(candidates[idx]);

        solve(candidates,
              target - candidates[idx],
              idx + 1,
              k,
              ans,
              output);

        // BACKTRACK
        output.remove(output.size() - 1);

        // EXCLUDE
        solve(candidates,
              target,
              idx + 1,
              k,
              ans,
              output);
    }

    public List<List<Integer>> combinationSum3(int k, int n) {

        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();

        int[] candidates = {1,2,3,4,5,6,7,8,9};

        solve(candidates, n, 0, k, ans, output);

        return ans;
    }
}