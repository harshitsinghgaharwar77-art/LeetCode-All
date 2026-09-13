class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        // Try every possible translation
        for(int rowShift = -(n - 1); rowShift <= n - 1; rowShift++) {
            for(int colShift = -(n - 1); colShift <= n - 1; colShift++) {

                int overlap = 0;

                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {

                        int x = i + rowShift;
                        int y = j + colShift;

                        // Check if translated position is inside img2
                        if(x >= 0 && x < n && y >= 0 && y < n) {

                            if(img1[i][j] == 1 && img2[x][y] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};