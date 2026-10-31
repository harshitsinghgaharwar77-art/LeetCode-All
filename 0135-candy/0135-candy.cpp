class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // give 1 candy to each child
        int candy = n;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            // increasing slope -> peak
            int peak = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
            }
            // decreasing slope
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }
            candy -= min(peak, dip);
        }
        return candy;
    }
};