class Solution {
    static int solve(List<List<Integer>> triangle, int rowIdx, int colIdx, Integer[][] dp) {

        if (rowIdx == triangle.size() - 1) {
            return triangle.get(rowIdx).get(colIdx);
        }

        if (dp[rowIdx][colIdx] != null) {
            return dp[rowIdx][colIdx];
        }

        int down = solve(triangle, rowIdx + 1, colIdx, dp);
        int diag = solve(triangle, rowIdx + 1, colIdx + 1, dp);

        return dp[rowIdx][colIdx] =
                triangle.get(rowIdx).get(colIdx) + Math.min(down, diag);
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        Integer[][] dp = new Integer[n][n];

        return solve(triangle, 0, 0, dp);
    }
}