
class Solution {
private:
    struct Store{
        int m_index;
        int m_location;
        Store() = default;
        Store(int index, int location) : m_index(index), m_location(location){}
    };
    
    struct StoreCompare{
        bool operator()(const Store& s1, const Store& s2) const{
            return s1.m_location < s2.m_location;
        }
    };
    
    int bsLower(const std::vector<int>& stores, int target) {
        
        int l = 0;
        int r = stores.size() - 1;
        int mid;
        while(l + 1 < r) {
            mid = l + (r - l) / 2;
            if(target > stores[mid]) l = mid;
            else r = mid;
        }
        
        if(stores[r] <= target) return r;
        if(stores[l] <= target) return l;
        return -1;        
    }
    
    int bsUpper(const std::vector<int>& stores, int target) {
        
        int l = 0;
        int r = stores.size() - 1;
        int mid;
        while(l + 1 < r) {
            mid = l + (r - l) / 2;
            if(target < stores[mid]) r = mid;
            else l = mid;
        }
        
        if(stores[l] >= target) return l;
        if(stores[r] >= target) return r;
        return -1;        
    }
public:
    /**
     * @param stores: The location of each store.
     * @param houses: The location of each house.
     * @return: The location of the nearest store to each house.
     */
    vector<int> findNearestStore(vector<int> &stores, vector<int> &houses) {

        sort(stores.begin(), stores.end());
        
        int len = houses.size();
        vector<int> answer(len, len - 1);
        for(int i = 0; i < len; ++i) {
            auto loc = houses[i];
            int lower = bsLower(stores, loc);
            int upper = bsUpper(stores, loc);
            if(lower == -1 && upper != -1) answer[i] = stores[upper];
            else if(upper == -1 && lower != -1) answer[i] = stores[lower];
            else {
                if(loc - stores[lower] <= stores[upper] - loc) answer[i] = stores[lower];
                else answer[i] = stores[upper];
            }
        }

        return answer;
        
    }
};