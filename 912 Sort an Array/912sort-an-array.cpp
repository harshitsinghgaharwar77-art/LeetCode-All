class Solution {
private:
    void merge(vector<int>& nums, int s, int e) {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> arr1(len1);
        vector<int> arr2(len2);

        int mainArrayIdx = s;

        for (int i = 0; i < len1; i++) {
            arr1[i] = nums[mainArrayIdx++];
        }

        mainArrayIdx = mid + 1;

        for (int i = 0; i < len2; i++) {
            arr2[i] = nums[mainArrayIdx++];
        }

        int idx1 = 0;
        int idx2 = 0;
        mainArrayIdx = s;

        while (idx1 < len1 && idx2 < len2) {
            if (arr1[idx1] < arr2[idx2]) {
                nums[mainArrayIdx++] = arr1[idx1++];
            } else {
                nums[mainArrayIdx++] = arr2[idx2++];
            }
        }

        while (idx1 < len1) {
            nums[mainArrayIdx++] = arr1[idx1++];
        }

        while (idx2 < len2) {
            nums[mainArrayIdx++] = arr2[idx2++];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e) {
            return;
        }

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);

        merge(nums, s, e);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};