/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */

class MiniTwitter {
private:
    typedef map<unsigned long, int, greater<unsigned long> > Map;
    typedef unordered_map<int, Map> TwitContainer;
    typedef unordered_map<int, unordered_set<int> > UserContainer;
    TwitContainer _twitContainer;
    UserContainer _userContainer;
    vector<Tweet> _tweets;
public:
    MiniTwitter() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        auto tweet = Tweet::create(user_id, tweet_text);
        _tweets.push_back(tweet);
        _twitContainer[user_id][_tweets.size() - 1] = user_id;
        for (auto user : _userContainer[user_id]) { _twitContainer[user][_tweets.size() - 1] = user_id; }
        return tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        vector<Tweet> temp;
        int i = 0;
        for (auto a : _twitContainer[user_id]) {
            if (i > 9) break;
            temp.push_back(_tweets[a.first]);
            ++i;
        }
        
        return temp;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        vector<Tweet> temp;
        int i = 0;
        for (auto a : _twitContainer[user_id]) {
            if(a.second == user_id) {
                temp.push_back(_tweets[a.first]);
                if(++i > 9) break;;
            }
        }
        
        return temp;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        if (from_user_id == to_user_id) return;
        _userContainer[to_user_id].insert(from_user_id);
        for (auto a : _twitContainer[to_user_id])
            if(a.second == to_user_id) _twitContainer[from_user_id][a.first] = a.second;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        if (_userContainer.count(to_user_id) == 0 || from_user_id == to_user_id) return;
        Map& tweets = _twitContainer[from_user_id];
        for (Map::iterator itr= tweets.begin(); itr != tweets.end(); ) {
            if (itr->second == to_user_id) tweets.erase(itr++);
            else ++itr;
        }
        _userContainer[to_user_id].erase(from_user_id);
    }
};

// Assum there will be a lot of follow and unfollow operations
class MiniTwitter {
private:
    std::vector<Tweet> m_allTweets;
    std::unordered_set<int> m_users;
    std::unordered_map<int, std::unordered_set<int>> m_followMap;
    std::unordered_map<int, std::vector<int>> m_userTweets;
public:
    MiniTwitter() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        if(m_users.count(user_id) == 0) {
            m_users.insert(user_id);
            m_followMap[user_id].insert(user_id);
        }
        auto tweet = Tweet::create(user_id, tweet_text);
        int idx = m_allTweets.size();
        m_allTweets.push_back(tweet);
        m_userTweets[user_id].push_back(idx);
        return tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        std::vector<Tweet> temp;
        int counter = 0;
        const auto& followedPeople = m_followMap[user_id];
        for (int i = m_allTweets.size() - 1; i > -1; --i) {
            const auto& tweet = m_allTweets[i];
            auto ownerId = tweet.user_id;
            if(followedPeople.count(ownerId) > 0) {
                temp.push_back(tweet);
                if(++counter > 9) break;
            }
        }
        
        return temp;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        std::vector<Tweet> temp;
        int counter = 0;
        const auto& tweets =  m_userTweets[user_id];
        for (int i =tweets.size() - 1; i > -1; --i) {
            temp.push_back(m_allTweets[tweets[i]]);
            if(++counter > 9) break;
        }
        
        return temp;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        m_followMap[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        if(m_followMap[from_user_id].count(to_user_id)) {
            m_followMap[from_user_id].erase(to_user_id);
        }
    }
};