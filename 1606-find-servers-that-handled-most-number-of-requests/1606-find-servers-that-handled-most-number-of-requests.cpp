class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for(int i = 0; i < k; i++){
            available.insert(i);
        }

        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> busy;

        vector<int> count(k, 0);

        int n = arrival.size();

        for(int i = 0; i < n; i++){

            while(!busy.empty() && busy.top().first <= arrival[i]){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()){
                continue;
            }

            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            if(it == available.end()){
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            count[server]++;

            long long finishTime = (long long)arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++){
            if(count[i] == maxi){
                ans.push_back(i);
            }
        }

        return ans;
    }
};