class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // totalsum - sum of minimum window
        int s =0, n = cardPoints.size();
        for(int x : cardPoints) s += x;
        int windowSize = n-k,sum = 0;
        // Initial window sum
        for(int i = 0; i < windowSize; i++) {
            sum += cardPoints[i];
        }
        int minSum = sum;
        for(int i = windowSize; i < n; i++){
            sum += cardPoints[i];
            sum -= cardPoints[i-windowSize];
            minSum= min(minSum, sum);
        }
        return s-minSum;
    }
};