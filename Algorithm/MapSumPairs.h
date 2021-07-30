#include "algorithmHeader.h"

#pragma once

class Trie {
public:
    map<char, Trie*> childs;
    int score;

    ~Trie() {
        map<char, Trie*>::iterator iter = childs.begin();
        for (; iter != childs.end(); ++iter) {
            delete iter->second;
        }
    }
};

class MapSum {
public:
    Trie root;
    map<string, int> keyMap;
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        int value = 0;
        if (keyMap.find(key) == keyMap.end()) {
            value = val;
            keyMap.insert(make_pair(key, val));
        }
        else {
            value = val - keyMap[key];
            keyMap[key] = val;
        }

        Trie* node = &root;
        node->score += value;

        for (int i = 0; i < key.length(); ++i) {
            if (node->childs.find(key[i]) != node->childs.end()) {
                node->childs[key[i]]->score += value;
                node = node->childs[key[i]];
            }
            else {
                Trie* newNode = new Trie;
                newNode->score = value;
                node->childs.insert(make_pair(key[i], newNode));

                node = newNode;
            } 
        }

    }

    int sum(string prefix) {
        Trie* node = &root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (node->childs.find(prefix[i]) != node->childs.end()) {
                node = node->childs[prefix[i]];
            }
            else {
                return 0;
            }
        }
        return node->score;
    }
};


/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */