//
//  main.cpp
//  LFU.leetcode
//
//  Created by lgu41 on 12/7/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct LRUNode {
    int _value;
    int _key;
    int _freq;
    LRUNode* _next;
    LRUNode* _prev;
    LRUNode(int key, int value) : _key(key), _value(value), _freq(1), _next(NULL), _prev(NULL) {}
};

struct LinkedList {
    LRUNode* _head;
    LRUNode* _tail;
    
    LinkedList(): _head(NULL), _tail(NULL) {}
    
    void addHead(LRUNode* node) {
        node->_next = _head;
        node->_prev = NULL;
        if (_head != NULL) {
            _head->_prev = node;
        }
        _head = node;
        if (_tail == NULL) {
            _tail = _head;
        }
    }
    
    void removeNode(LRUNode* node){
        if (node->_prev != NULL) {
            node->_prev->_next = node->_next;
        } else {
            _head = node->_next;
        }
        
        if (node->_next != NULL) {
            node->_next->_prev = node->_prev;
        } else {
            _tail = node->_prev;
        }
        
    }
};

typedef std::unordered_map<int, LRUNode*> LRUContainer;
typedef std::unordered_map<int, LinkedList> LFUContainer;
typedef LRUContainer::iterator LruIter;
typedef LFUContainer::iterator LfuIter;



class LFUCache {
    int _capacity;
    int _lowestFreq;
    LRUContainer _data;
    LFUContainer _freqMap;
public:
    LFUCache(int capacity) : _capacity(capacity), _lowestFreq(1) {
        _data = LRUContainer(capacity);
    }
    
    int get(int key) {
        if (_capacity == 0) return -1;
        LruIter itr = _data.find(key);
        if(itr != _data.end()) {
            LRUNode* node = itr->second;
            LfuIter fItr = _freqMap.find(node->_freq++);
            fItr->second.removeNode(node);
            if (fItr->second._head == NULL) {
                _freqMap.erase(fItr);
            }
            if (_freqMap.find(_lowestFreq) == _freqMap.end()) {
                _lowestFreq = node->_freq;
            }
            _freqMap[node->_freq].addHead(node);
            
            return node->_value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (_capacity == 0) return;
        LruIter fItr = _data.find(key);
        if (fItr == _data.end()) {
            LRUNode* newNode = new LRUNode(key, value);
            if (_data.size() == _capacity) {
                LfuIter iItr = _freqMap.find(_lowestFreq);
                LinkedList& list = iItr->second;
                _data.erase(list._tail->_key);
                list.removeNode(list._tail);
            }
            _freqMap[1].addHead(newNode);
            _data[key] = newNode;
            _lowestFreq = 1;
        } else {
            LRUNode* node = fItr->second;
            node->_value = value;
            LfuIter fItr = _freqMap.find(node->_freq++);
            fItr->second.removeNode(node);
            if(fItr->second._head == NULL) {
                _freqMap.erase(fItr);
            }
            LinkedList& list =_freqMap[node->_freq];
            if (_freqMap.find(_lowestFreq) == _freqMap.end()) {
                _lowestFreq = node->_freq;
            }
            node->_prev = NULL;
            node->_next = NULL;
            list.addHead(node);
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
    LFUCache cache(2);
    cache.set(1,1);
    cache.set(2,2);
    std::cout << cache.get(1) << std::endl;
    cache.set(3,3);
    std::cout << cache.get(2) << std::endl;
    std::cout << cache.get(3) << std::endl;
    cache.set(4,4);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;*/
    LFUCache cache(2);
    cache.set(3,1);
    cache.set(2,1);
    cache.set(2,2);
    cache.set(4,4);
    std::cout << cache.get(2) << std::endl;
    return 0;
}
