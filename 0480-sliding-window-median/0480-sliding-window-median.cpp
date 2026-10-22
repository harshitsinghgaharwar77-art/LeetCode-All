class Solution {
public:
    multiset<pair<int, int>> minHeap, maxHeap;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<double> result;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Remove the element leaving the sliding window
            if (i >= k) {
                pair<int, int> old = {nums[i - k], i - k};

                minHeap.erase(old);
                maxHeap.erase(old);
            }

            // Always add value to minHeap first
            minHeap.insert({nums[i], i});

            // Shift first value from minHeap to maxHeap
            auto it = minHeap.begin();
            maxHeap.insert(*it);
            minHeap.erase(it);

            // Balance these heaps
            balanceHeaps();

            // Calculate median once window reaches size k
            if (i >= k - 1) {
                result.push_back(getMedian(k));
            }
        }

        return result;
    }

    double getMedian(int k) {
        if (k % 2 == 0) {
            return ((double)maxHeap.rbegin()->first +
                    (double)minHeap.begin()->first) / 2.0;
        }

        return (double)minHeap.begin()->first;
    }

    void balanceHeaps() {
        // maxHeap must never be larger than minHeap
        if (maxHeap.size() > minHeap.size()) {
            auto it = prev(maxHeap.end());
            pair<int, int> value = *it;

            maxHeap.erase(it);
            minHeap.insert(value);
        }

        // minHeap can have at most one extra element
        if (minHeap.size() > maxHeap.size() + 1) {
            auto it = minHeap.begin();
            pair<int, int> value = *it;

            minHeap.erase(it);
            maxHeap.insert(value);
        }
    }
};