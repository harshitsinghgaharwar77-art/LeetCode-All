class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR gives 1 at positions where bits are different
        int n = start ^ goal;
        // Count the number of set bits
        int count = 0;
        while(n > 0) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};