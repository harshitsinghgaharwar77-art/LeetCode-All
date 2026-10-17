class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        // we had to find the rectangle with the maximum area 
        int area = 0, maxAreaa = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         int num = min(height[i],height[j]);
        //         int dist = abs(i-j);
        //         area = num * dist;
        //         maxAreaa = max(area, maxAreaa);
        //     }
        // }
        // return maxAreaa;

        // optimised approach 2 pointer
        int i = 0, j = n-1;
        while(i <= j){
            int num = min(height[i],height[j]);
            int dist = abs(i-j);
            area = num * dist;
            maxAreaa = max(area, maxAreaa);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxAreaa;
    }
};