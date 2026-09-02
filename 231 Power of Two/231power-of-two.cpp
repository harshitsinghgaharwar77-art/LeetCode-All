class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        // A power of 2 has exactly one set bit in its binary representation.
        // For any power of 2:
        // eg-> 7-> 0111 8-> 1000 their and is zero
        if((n & (n - 1)) == 0)  return true;
        else   return false;
    }
};