class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        // if n is odd add zero to the result.
        if ( n % 2 ==1) 
        {
            result.push_back(0);
        }
        // add pairs of (i,-i)
        for ( int i = 1; i <= n/2 ; ++i)
        {
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};