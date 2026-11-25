
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int cnt[11] = {0};

            for(int j = i; j < n; j++) {
                int x = nums[j];

                for(int p = 2; p <= x; p++) {
                    if(x % p == 0) {
                        cnt[p]++;

                        while(x % p == 0) {
                            x /= p;
                        }
                    }
                }

                int len = j - i + 1;
                bool valid = true;

                if(len >= 3) {
                    for(int p = 2; p <= 10; p++) {
                        if(cnt[p] > 1) {
                            valid = false;
                            break;
                        }
                    }
                }

                if(!valid) {
                    break;
                }

                if(len >= 2 || nums[i] == 1) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
