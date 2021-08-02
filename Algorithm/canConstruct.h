#include "algorithmHeader.h"
#pragma once

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransomMap;
        for (int i = 0; i < magazine.length(); ++i) {
            ransomMap[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.length(); ++i) {
            if (ransomMap.find(ransomNote[i]) == ransomMap.end()) {
                return false;
            }
            else {
                if (ransomMap[ransomNote[i]] > 0) {
                    ransomMap[ransomNote[i]]--;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
