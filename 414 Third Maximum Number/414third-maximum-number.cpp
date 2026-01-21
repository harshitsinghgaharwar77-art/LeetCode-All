class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        for (int x : nums) {
            s.insert(x);
            if (s.size() > 3)
                s.erase(s.begin()); // remove smallest
        }

        if (s.size() < 3)
            return *s.rbegin(); // max element

        return *s.begin(); // third maximum
    }
};
