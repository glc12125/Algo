class Solution {
public:
    /**
     * @param ghosts: a 2D integer array
     * @param target: a integer array
     * @return: return boolean
     */
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int dist = abs(target[0]) + abs(target[1]);
        for(int i=0; i<ghosts.size(); i++) {
            int tmp_dist = abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]);
            if (tmp_dist <= dist) return false;
        }
        return true;
    }
};