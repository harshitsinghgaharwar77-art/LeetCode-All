class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRows = matrix.size();
        int totalColumns = matrix[0].size();
        int s = 0, e = totalRows * totalColumns - 1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            int rowIdx = mid/totalColumns;
            int colIdx = mid % totalColumns;
            if(matrix[rowIdx][colIdx] == target){
                return true;
            }
            if(matrix[rowIdx][colIdx] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return false;
    }
};