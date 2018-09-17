//
//  main.cpp
//  island_perimeter.leetcode
//
//  Created by lgu41 on 11/25/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

typedef pair<unsigned int, unsigned int> Key;
typedef unordered_map<Key, unsigned int, pair_hash> Container;
class Solution {
    Container container;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int result = 0;
        for(unsigned int i = 0; i < grid.size(); ++i) {
            for(unsigned int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    container[Key(i, j)] = 1;
                    result += 4;
                    result -= (j > 0 ? (container[Key(i, j-1)] ? 2: 0) : 0);
                    result -= (i > 0 ? (container[Key(i-1, j)] ? 2: 0) : 0);
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0;
        for ( int i = 0; i < grid.size(); i++ ) {
            for ( int j = 0; j < grid[i].size(); j++ ) {
                if ( grid[i][j] == 1 ) {
                    int num = 4;
                    if ( (i > 0 && grid[i-1][j] > 0) )
                        num--;
                    if (j > 0 && grid[i][j-1] > 0)
                        num--;
                    if (i < grid.size()-1 && grid[i+1][j] > 0 )
                        num--;
                    if ( j < grid[i].size()-1 && grid[i][j+1] > 0 )
                        num--;
                    perimeter += num;
                }
            }
        }
        return perimeter;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
