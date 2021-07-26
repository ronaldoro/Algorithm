#include "algorithmHeader.h"
#pragma once


class Solution {
public:
    int solution(string s) {
        string answerStr;
        for (int i = 0; i < s.length(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                answerStr += s[i];
                continue;
            }

            if (s[i] == 'z') { // zero
                answerStr += '0';
                i += 3;
                continue;
            }

            if (s[i] == 'o') { // one
                answerStr += '1';
                i += 2;
                continue;
            }

            if (s[i] == 't') { // two or three
                if (s[i + 1] == 'w') { // two
                    answerStr += '2';
                    i += 2;
                }
                else { // three
                    answerStr += '3';
                    i += 4;
                }
                continue;
            }

            if (s[i] == 'f') { // four or five
                if (s[i + 1] == 'o') // four
                    answerStr += '4';
                else // five
                    answerStr += '5';
                i += 3;
                continue;
            }

            if (s[i] == 's') { // six or seven
                if (s[i + 1] == 'i') { // six
                    answerStr += '6';
                    i += 2;
                }
                else { // seven
                    answerStr += '7';
                    i += 4;
                }
                continue;
            }

            if (s[i] == 'e') { // eight
                answerStr += '8';
                i += 4;
                continue;
            }

            if (s[i] == 'n') { // nine
                answerStr += '9';
                i += 3;
                continue;
            }
        }

        return stoi(answerStr);
    }
};