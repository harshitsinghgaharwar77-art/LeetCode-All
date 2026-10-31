class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int i = 0, j = n-1, boat = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                // both can share the same boat
                i++;j--;
            }else{
                // Heaviest person goes alone
                j--;
            }
            boat++;
        }
        return boat;
    }
};