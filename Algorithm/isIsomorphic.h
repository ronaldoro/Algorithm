#include "algorithmHeader.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() == 0)
            return true;

        map<char, char> temp;
        map<char, char> temp2;
        temp[s[0]] = t[0];
        temp2[t[0]] = s[0];

        for (int i = 1; i < s.length(); ++i) {
            if (temp.find(s[i]) == temp.end() && temp2.find(t[i]) == temp2.end()) {
                temp[s[i]] = t[i];
                temp2[t[i]] = s[i];
            }
            else {
                if (temp[s[i]] != t[i])
                    return false;
                if (temp2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};