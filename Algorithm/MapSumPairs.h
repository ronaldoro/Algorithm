#include "algorithmHeader.h"

#pragma once

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
        }

        Trie& node = root;
        node.score += value;

        for (int i = 0; i < key.length(); ++i) {
            if (node.childs.find(key[i]) != node.childs.end()) {
                node.childs[i].score += val;
                node = node.childs[i];
            }
            else {
                Trie node;
                node.childs.insert(make_pair(key[i], node));
            } 
        }

    }

    int sum(string prefix) {
        Trie node = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (node.childs.find(prefix[i]) != node.childs.end()) {
                node = node.childs[prefix[i]];
            }
            else {
                return 0;
            }
        }
        return node.score;
    }
};

class Trie {
public:
    map<char, Trie> childs;
    int score;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */