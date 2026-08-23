class Twitter {
    // id's are unique so it is also one reason to use set
    unordered_map<int, unordered_set<int>> friends;
    vector<pair<int, int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int n = 0;
        for(int i = posts.size()-1; i >= 0 && n < 10; i--){
            if(posts[i].first == userId || friends[userId].count(posts[i].first)){
                ans.push_back(posts[i].second);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */