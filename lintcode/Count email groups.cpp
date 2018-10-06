class Solution {
private:
    std::unordered_map<std::string, int> m_groupCountContainer;
    
    std::string parseEmail(const std::string& email) {
        std::string parsed;
        bool ignore = false;
        bool stopIgnoring = false;
        for(auto& c : email) {
            if(c == '.' && !stopIgnoring) continue;
            if(c == '+' && !ignore && !stopIgnoring) {
                ignore = true;
                continue;
            }
            if(c == '@') {
                ignore = false;
                stopIgnoring = true;
                parsed += c;
                continue;
            }
            if(!ignore || stopIgnoring) parsed += c;
        }
        std::cout << "parsed email: " << parsed << "\n";
        return parsed;
    }
public:
    /**
     * @param emails: Original email
     * @return: Return the count of groups which has more than one email address in it.
     */
    int countGroups(vector<string> &emails) {
        std::unordered_set<std::string> resultSet;
        for(auto email : emails) {
            const auto& parsedEmail = parseEmail(email);
            if(++m_groupCountContainer[parsedEmail] > 1) {
                resultSet.insert(parsedEmail);
            }
        }
        return resultSet.size();
    }
};