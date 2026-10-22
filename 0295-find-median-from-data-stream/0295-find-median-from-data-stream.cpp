
class MedianFinder {
public:
    priority_queue<int> left_maxHeap;
    priority_queue<int, vector<int>, greater<int>> right_minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left_maxHeap.empty() || num < left_maxHeap.top()) {
            left_maxHeap.push(num);
        } else {
            right_minHeap.push(num);
        }

        // Maintain left_maxHeap size equal to right_minHeap
        // or one greater than right_minHeap

        if (left_maxHeap.size() > right_minHeap.size() + 1) {
            right_minHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        } else if (left_maxHeap.size() < right_minHeap.size()) {
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }
    
    double findMedian() {
        if (left_maxHeap.size() == right_minHeap.size()) {
            // Even number of elements
            return ((long long)left_maxHeap.top() +
                    right_minHeap.top()) / 2.0;
        } else {
            // Odd number of elements
            return left_maxHeap.top();
        }
    }
};
