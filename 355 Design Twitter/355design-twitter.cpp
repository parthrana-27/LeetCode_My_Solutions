class Twitter {

public:
    int ts;
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweets;
    Twitter() {
        ts=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        following[userId].insert(userId);
        for(auto f:following[userId]){
            for(auto t:tweets[f]){
                int time=t.first;
                int user=t.second;
                pq.push({time,user});
            }
        }
        vector<int>feed;
        for(int i=0;i<10 && !pq.empty();i++){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) following[followerId].erase(followeeId);
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