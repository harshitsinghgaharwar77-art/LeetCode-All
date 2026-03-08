class Solution {
public:
    int mySqrt(int x) {
        // base case
        if(x == 0 || x == 1)
        {
            return x;
        }
        int s = 1, e = x;
        int ans = 0;
        while(s <= e)
        {
            long long int mid = s + (e-s)/2;
            if(mid * mid == x)
            {
                return mid;
            }
            if(mid * mid < x)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};