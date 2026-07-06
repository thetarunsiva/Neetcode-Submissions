class Twitter {
public:
    int t = 0;
    unordered_map<int, vector<pair<int, int>>> user_tweets;
    unordered_map<int, set<int>> user_followers;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (user_tweets.contains(userId)) {
            user_tweets[userId].push_back({t, tweetId});
            t++;
        }
        else {
            vector<pair<int, int>> pq = {{t, tweetId}};
            t++;
            user_tweets[userId] = pq;
            if (!user_followers.contains(userId)) {
                set<int> v = {userId};
                user_followers[userId] = v;
            }
        }

    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed = {};
        set<int> following = user_followers[userId];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> big_feed;
        int jj = 0;
        for (int i : following) {
            for (pair<int, int> j : user_tweets[i]) {
                if (jj == 10 && j.first > big_feed.top().first) {
                    big_feed.pop();
                    big_feed.push(j);
                }
                else if (jj < 10) {
                    big_feed.push(j);
                    jj++;
                }
            }
        }
        while (!big_feed.empty()) {
            int tweet = big_feed.top().second;
            feed.push_back(tweet);
            big_feed.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (user_followers.contains(followerId)) {
            user_followers[followerId].insert(followeeId);
        }
        else {
            set<int> v = {followerId, followeeId};
            user_followers[followerId] = v;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followers[followerId].erase(followeeId);
    }
};
