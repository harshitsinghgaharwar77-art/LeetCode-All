class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        // edge case
        if(n % groupSize != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            if(mpp[hand[i]] == 0){
                pq.push(hand[i]);
            }
            mpp[hand[i]]++;
        }
        while(!pq.empty()){
            int card = pq.top();
            // smallest card is alreday used
            if(mpp[card]==0){
                pq.pop();
                continue;
            }
            // frequency of the smallest card
            int freq = mpp[card];
            // form consecutive groups
            for(int i = 0; i < groupSize; i++){
                if(mpp[card+i] < freq){
                    return false;
                }
                mpp[card+i] -= freq;
            }
        }
        return true;
    }
};