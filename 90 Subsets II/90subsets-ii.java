class Solution {
    static void solve(int[] nums, int idx, List<Integer> output, List<List<Integer>> ans) {
        // base case
        if (idx >= nums.length) {
            ans.add(new ArrayList<>(output));
            return;
        }

        // Include current element
        output.add(nums[idx]);
        solve(nums, idx + 1, output, ans);

        // Backtrack
        output.remove(output.size() - 1);

        // Skip all duplicate elements while excluding
        while (idx + 1 < nums.length && nums[idx] == nums[idx + 1]) {
            idx++;
        }

        // Exclude current element
        solve(nums, idx + 1, output, ans);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();

        solve(nums, 0, output, ans);

        return ans;
    }
}