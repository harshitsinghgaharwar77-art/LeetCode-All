class Solution {
    // private:
    // vector<int> getLeftMaxArray(vector<int>& height, int &n){
    //     vector<int> leftMax(n);
    //     leftMax[0] = height[0];
    //     for(int i = 1; i < n; i++){
    //         leftMax[i] = max(leftMax[i-1], height[i]);
    //     }
    //     return leftMax;
    // }

    // vector<int> getRightMaxArray(vector<int>& height, int &n){
    //     vector<int> rightMax(n);
    //     rightMax[n-1] = height[n-1];
    //     for(int i = n-2; i >= 0; i--){
    //         rightMax[i] = max(rightMax[i+1], height[i]);
    //     }
    //     return rightMax;
    // }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        // count of khali 1x1 squares between two bars
        // vector<int> leftMaxArray = getLeftMaxArray(height, n);
        // vector<int> rightMaxArray = getRightMaxArray(height, n);
        
        // for(int i = 0; i < n; i++){
        //     int h = min(leftMaxArray[i], rightMaxArray[i]) - height[i];
        //     sum += h;
        // }

        // optimised approach O(1) space two pointer
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }
                else{
                    sum += leftMax - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }
                else{
                    sum += rightMax - height[right];
                }
                right--;
            }
        }
        return sum;
    }
};