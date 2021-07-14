#include "algorithmHeader.h"

#pragma once
class Solution {
public:
    string customSortString(string order, string str) {
        string temp;
        for(int i = 0; i < order.length(); ++i){
            while(str.find(order[i]) != -1) {
                temp += order[i];
                str.erase(find(str.begin(), str.end(), order[i]));    
            }
            
        }
    
        return temp + str;   
    }

};