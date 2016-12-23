//
//  main.cpp
//  getRandom.leetcode
//
//  Created by lgu41 on 12/19/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class RandomizedCollection {
private:
    typedef pair<int, int> Pair;
    unordered_map<int, vector<unsigned long> > _container;
    vector<Pair> _vec;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        _container[val].push_back(_vec.size());
        _vec.push_back(Pair(val, _container[val].size() - 1));
        return _container[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (_container[val].size() == 0) return false;
        unsigned long key = _container[val].back();
        _container[val].pop_back();
        
        if (key != _vec.size() - 1) {
            Pair tmp = _vec.back();
            _vec[key] = tmp;
            _vec[key].second = tmp.second;
            _container[tmp.first][tmp.second] = key;
        }
        
        _vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return _vec[rand() % _vec.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/*
 ["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
 [[],[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]
 
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    RandomizedCollection r;
    r.insert(10);
    r.insert(10);
    r.insert(20);
    r.insert(20);
    r.insert(30);
    r.insert(30);
    r.remove(10);
    r.remove(10);
    r.remove(30);
    r.remove(30);
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    std::cout << "getRandom: " << r.getRandom() << endl;
    return 0;
}
