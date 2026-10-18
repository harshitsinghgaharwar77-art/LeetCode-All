class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int ans = 0;
        long long arrow = LLONG_MIN;
        for (auto point : points) {
            if (ans == 0 || point[0] > arrow) {
                ans++;
                arrow = point[1];
            }
        }
        return ans;
    }
};