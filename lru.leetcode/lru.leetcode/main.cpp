//
//  main.cpp
//  lru.leetcode
//
//  Created by Liangchuan Gu on 10/31/16.
//  Copyright © 2016 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <unordered_map>

struct LRUNode {
    int _value;
    int _key;
    LRUNode* _next;
    LRUNode* _prev;
    LRUNode(int key, int value) : _key(key), _value(value), _next(NULL), _prev(NULL) {}
};

typedef std::unordered_map<int, LRUNode*> LRUContainer;
typedef LRUContainer::iterator MapIter;

class LRUCache{
private:
    int _capacity;
    LRUNode* _head;
    LRUNode* _tail;
    LRUContainer _container;
    
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
public:
    LRUCache(int capacity) : _capacity(capacity), _head(NULL), _tail(NULL) {
        
    }
    
    ~LRUCache(){
        while(_head) {
            LRUNode* temp = _head->_next;
            delete _head;
            _head = temp;
        }
    }
    
    int get(int key) {
        
        MapIter itr = _container.find(key);
        if(itr != _container.end()) {
            LRUNode* node = itr->second;
            removeNode(node);
            addHead(node);
            return node->_value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        MapIter fItr = _container.find(key);
        if (fItr == _container.end()) {
            LRUNode* newNode = new LRUNode(key, value);
            if (_container.size() == _capacity) {
                MapIter iItr = _container.find(_tail->_key);
                removeNode(_tail);
                _container.erase(iItr);
            }
            addHead(newNode);
            _container[key] = newNode;
        } else {
            LRUNode* node = fItr->second;
            node->_value = value;
            removeNode(node);
            addHead(node);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    LRUCache cache(1);
    cache.set(2, 1);
    std::cout << "get(2): " << cache.get(2) << std::endl;
    cache.set(3, 2);
    std::cout << "get(2): " << cache.get(2) << std::endl;
    std::cout << "get(3): " << cache.get(3) << std::endl;

    return 0;
}
