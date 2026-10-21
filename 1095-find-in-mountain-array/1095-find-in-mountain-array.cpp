
class Solution {
public:
    int peakIdx(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                s = mid + 1;
            else
                e = mid;
        }
        return s;
    }

    // Ascending order
    int binarySearch(int target, MountainArray &mountainArr, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;
            else if (val < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }

    // Descending order
    int binarySearchDesc(int target, MountainArray &mountainArr, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;
            else if (val < target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peakIdx(mountainArr);

        // Search ascending part first for the smallest index
        int res = binarySearch(target, mountainArr, 0, idx);
        if (res != -1) return res;

        // Search descending part
        return binarySearchDesc(target, mountainArr, idx + 1, n - 1);
    }
};
