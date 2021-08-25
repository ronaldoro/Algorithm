#include "algorithmHeader.h"
#pragma once

class Solution {
public:
    int minCut(string s) {
        queue<pair<int, int>> que;
        que.push(make_pair(0, s.length() - 1));

        bool isNext = false;
        int latestRight = 0;
        int result = 0;
        while (que.empty() == false) {
            int left = isNext ? latestRight + 1 : que.front().first;
            int right = isNext ? s.length() - 1 : que.front().second;
            bool isPalindrome = true;

            while (left < right) {    
                int leftTemp = left;
                int rightTemp = right;

                isPalindrome = true;
                while (leftTemp < rightTemp) {
                    if (s[leftTemp++] != s[rightTemp--]) {
                        --right;
                        leftTemp = left;
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome == true)
                    break;
            }


            isNext = isPalindrome || (left == right);
            if (isNext) {
                if (right == s.length() - 1)
                    break;

                ++result;
                latestRight = right;
                que.push(make_pair(left, right));
            }
            
            que.pop();

        }

        return result;
    }
};