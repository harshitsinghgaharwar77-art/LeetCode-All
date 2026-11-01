class KthLargest {
public:
    int k;
    // hum min heap ka use karenge
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        // constructor
        this->k = k;
        // priority queue mein push karo jab tk uska size k ko exceed na kr jaye
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        // priority queue mein push karo jab tk uska size k ko exceed na kr jaye
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        // humara answer top pe hoga pq ke
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */