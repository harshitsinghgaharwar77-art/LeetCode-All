class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
            }
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};