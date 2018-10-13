public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        int len = dict.size();
        if(len == 0) return 0;
        if(start.size() < 1 || start.size() != end.size()) return 0;
        if(start == end) return 1;
        std::queue<std::string> q;
        q.push(start);
        std::unordered_set<std::string> visited;
        visited.insert(start);

        //dict.insert(start);
        dict.insert(end);
        int steps = 0;
        while(!q.empty()) {
            ++steps;
            int currentQLen = q.size();
            while(currentQLen > 0) {
                auto word = q.front();
                q.pop();
                if(word == end) return steps;
                int n = word.size();
                for(int i = 0; i < n; ++i) {
                    char original = word[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(c != word[i]) {
                            word[i] = c;
                            if(dict.count(word) > 0 && visited.count(word) == 0) {
                                q.push(word);
                                visited.insert(word);
                            }
                        }
                    }
                    word[i] = original;
                }
                --currentQLen;
            }
        }
        return 0;
    }
};