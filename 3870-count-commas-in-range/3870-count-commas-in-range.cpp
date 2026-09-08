class Solution {
public:
    long long countCommas(int n) {
        long long total_commas = 0;
        long long threshold = 1000;
        
        while (n >= threshold) {
            // Add 1 comma for every number greater than or equal to the current threshold
            total_commas += (n - threshold + 1);
            
            // Move to the next threshold (e.g., from 1,000 to 1,000,000)
            threshold *= 1000;
        }
        
        return total_commas;
    }
};