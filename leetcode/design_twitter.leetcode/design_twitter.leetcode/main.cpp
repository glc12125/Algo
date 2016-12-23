//
//  main.cpp
//  design_twitter.leetcode
//
//  Created by lgu41 on 12/20/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <map>

using namespace std;

class Twitter {
private:
    typedef map<unsigned long, int, greater<unsigned long> > Map;
    typedef unordered_map<int, Map> TwitContainer;
    typedef unordered_map<int, unordered_set<int> > UserContainer;
    TwitContainer _twitContainer;
    UserContainer _userContainer;
    vector<int> _tweets;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        _tweets.push_back(tweetId);
        _twitContainer[userId][_tweets.size() - 1] = userId;
        for (auto user : _userContainer[userId]) { _twitContainer[user][_tweets.size() - 1] = userId; }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> temp;
        int i = 0;
        for (auto a : _twitContainer[userId]) {
            if (i > 9) break;
            temp.push_back(_tweets[a.first]);
        }
        
        return temp;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        _userContainer[followeeId].insert(followerId);
        for (auto a : _twitContainer[followeeId])
            if(a.second == followeeId) _twitContainer[followerId][a.first] = a.second;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (_userContainer.count(followeeId) == 0 || followerId == followeeId) return;
        Map& tweets = _twitContainer[followerId];
        for (Map::iterator itr= tweets.begin(); itr != tweets.end(); ) {
            if (itr->second == followeeId) tweets.erase(itr++);
            else ++itr;
        }
        _userContainer[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

void prinVec(const vector<int>& vec) {
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Twitter t;
    t.postTweet(1,5);
    cout << "twitter.getNewsFeed(1)\n";
    prinVec(t.getNewsFeed(1));
    t.follow(1,2);
    t.postTweet(2,6);
    cout << "twitter.getNewsFeed(1)\n";
    prinVec(t.getNewsFeed(1));
    t.unfollow(1,2);
    cout << "twitter.getNewsFeed(1)" << endl;
    prinVec(t.getNewsFeed(1));
    
    Twitter t1;
    t1.postTweet(1,1);
    cout << "t1.getNewsFeed(1)\n";
    prinVec(t1.getNewsFeed(1));
    t1.follow(2,1);
    cout << "t1.getNewsFeed(2)\n";
    prinVec(t1.getNewsFeed(2));
    t1.unfollow(2,1);
    cout << "t1.getNewsFeed(2)" << endl;
    prinVec(t1.getNewsFeed(2));

    return 0;
}
