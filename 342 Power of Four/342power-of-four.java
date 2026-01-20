class Solution {
    public boolean solve(int n){
        // base case
        if(n == 1){
            return true;
        }
        if(n <= 0 || n%4!=0){
            return false;
        }
        return solve(n/4);
    }
    public boolean isPowerOfFour(int n) {
        return solve(n);
    }
}