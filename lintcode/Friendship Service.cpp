class FriendshipService {
private:
    std::unordered_map<int, std::set<int>> m_followingMap;
    std::unordered_map<int, std::set<int>> m_followerMap;
public:
    FriendshipService() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @return: all followers and sort by user_id
     */
    vector<int> getFollowers(int user_id) {
        vector<int> result(m_followerMap[user_id].begin(), m_followerMap[user_id].end());
        return result;
    }

    /*
     * @param user_id: An integer
     * @return: all followings and sort by user_id
     */
    vector<int> getFollowings(int user_id) {
        vector<int> result(m_followingMap[user_id].begin(), m_followingMap[user_id].end());
        return result;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int to_user_id, int from_user_id) {
        m_followingMap[from_user_id].insert(to_user_id);
        m_followerMap[to_user_id].insert(from_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int to_user_id, int from_user_id) {
        m_followingMap[from_user_id].erase(to_user_id);
        m_followerMap[to_user_id].erase(from_user_id);
    }
};