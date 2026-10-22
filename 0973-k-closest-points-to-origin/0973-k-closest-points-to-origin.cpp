class Solution {
    private:
    int getDist(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (x2 - x1) + 
               (y2 - y1) * (y2 - y1);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return getDist(a[0], a[1], 0, 0) < 
                   getDist(b[0], b[1], 0, 0);
        });

        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};