class Solution {
private:
    int getKey(const vector<int>& needs) {
        int key = 0;
        int base = 10;
        int multiplier = 1;
        for(int i = needs.size() - 1; i >= 0; --i) {
            key += needs[i] * multiplier;
            multiplier *= base;
        }
        return key;
    }

    bool isSpecialValid(const vector<int>& special, const vector<int>& needs) {
        int len = needs.size();
        for(int i = 0; i < len; ++i) {
            if(special[i] > needs[i]) return false;
        }
        return true;
    }

    void updateNeeds(bool reverse, const vector<int>& special, vector<int>& needs) {
        int len = needs.size();
        for(int i = 0; i < len; ++i) {
            if(reverse) needs[i] += special[i];
            else needs[i] -= special[i];
        }
    }

    int dfs(const vector<int> &price, const vector<vector<int>> &special, vector<int>& needs, unordered_map<int, int>& mem) {
        int key = getKey(needs);
        if(mem.count(key)) return mem[key];

        int needsNum = needs.size();
        int specialNum = special.size();
        int cost = 0;
        for(int i = 0; i < needsNum; ++i) {
            if(needs[i] > 0) cost += needs[i] * price[i];
        }
        for(int i = 0; i < specialNum; ++i) {
            const auto& offer = special[i];
            if(!isSpecialValid(offer, needs)) continue;
            updateNeeds(false, offer, needs);
            cost = std::min(cost, dfs(price, special, needs, mem) + offer.back());
            updateNeeds(true, offer, needs);
        }

        mem[key] = cost;
        return mem[key];
    }
public:
    /**
     * @param price: List[int]
     * @param special: List[List[int]]
     * @param needs: List[int]
     * @return: return an integer
     */
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        unordered_map<int, int> mem;
        return dfs(price, special, needs, mem);
    }
};