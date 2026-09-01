class Solution {
public:
    long long ans = 0;

    void merge(vector<int>& a, int l, int m, int r) {
        int leftSize = m - l + 1;
        int rightSize = r - m;

        vector<int> left(leftSize), right(rightSize);

        for (int i = 0; i < leftSize; i++) {
            left[i] = a[l + i];
        }

        for (int i = 0; i < rightSize; i++) {
            right[i] = a[m + 1 + i];
        }

        int i = 0, j = 0, cnt = 0;

        for (int i = 0; i < leftSize; i++) {
            while (j < rightSize && left[i] > (long long)2 * right[j]) {
                j++;
            }
            cnt += j;
        }

        ans += cnt;

        i = 0, j = 0;
        int k = l;

        while (i < leftSize && j < rightSize) {
            if (left[i] > right[j]) {
                a[k++] = right[j++];
            } else {
                a[k++] = left[i++];
            }
        }

        while (i < leftSize) {
            a[k++] = left[i++];
        }

        while (j < rightSize) {
            a[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& a, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);

            merge(a, l, m, r);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums, 0, n - 1);

        return ans;
    }
};