#include "algorithmHeader.h"

#pragma once

class Solution {
public:
    bool visited[1001] = {};

    bool isAdjacent(string str1, string str2) {
        int diff = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                ++diff;
            }
        }

        if (diff == 1)
            return true;

        return false;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        if (wordList.size() == 0)
            return result;

        queue<vector<string>> stringsQue;
        queue<int> indexQue;
        bool none = true;
        for (int i = 0; i < wordList.size(); ++i) {
            if (endWord == wordList[i])
                none = false;
            if (isAdjacent(beginWord, wordList[i]) == true) {
                indexQue.push(i);
                visited[i] = true;

                vector<string> strings = { beginWord, wordList[i] };
                stringsQue.push(strings);

                if (endWord == wordList[i]) {
                    visited[i] = false;
                    result.push_back(strings);
                }
            }
        }

        if (none == true)
            return result;

        //find by Bfs
        bool find = false;
        while (result.empty() == true && indexQue.empty() == false) {
            int queSize = indexQue.size();

            for (int que = 0; que < queSize; ++que) {
                int index = indexQue.front();
                visited[index] = true;

                for (int i = 0; i < wordList.size(); ++i) {
                    if (visited[i] == true)
                        continue;

                    if (isAdjacent(wordList[index], wordList[i]) == true) {
                        indexQue.push(i);

                        vector<string> strings = stringsQue.front();
                        strings.push_back(wordList[i]);
                        stringsQue.push(strings);

                        if (endWord == wordList[i]) {
                            visited[i] = false;
                            result.push_back(strings);
                        }
                    }
                }

                indexQue.pop();
                stringsQue.pop();
            }

        }

        return result;
    }
};