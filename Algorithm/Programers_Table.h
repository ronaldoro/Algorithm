#include "algorithmHeader.h"
#pragma once


class Solution {
public:
    string solution(int n, int k, vector<string> cmd) {
        string answer = "";

        int cur = k;
        set<int> tableSet;
        stack<int> deleteStack;

        for (int i = 0; i < n; ++i) {
            answer += 'X';
            tableSet.insert(i);
        }
            

        std::set<int>::iterator current = tableSet.find(k);

        for (int i = 0; i < cmd.size(); ++i) {
            if (cmd[i].length() == 1) { //C or Z

                if (cmd[i][0] == 'C') {
                    std::set<int>::iterator next = current;
                    next++;
                    if (next != tableSet.end()) {
                        cur = (*next);
                    }
                    else {
                        next = current;
                        next--;
                        cur = (*next);
                    }

                    deleteStack.push(*current);
                    tableSet.erase(current);

                    current = next;
                }
                else {
                    if (deleteStack.empty() == false) {
                        tableSet.insert(deleteStack.top());
                        deleteStack.pop();
                    }
                }

            }
            else { //U X or D X
                int move = stoi(cmd[i].substr(1, cmd[i].length()-1));
                if (cmd[i][0] == 'D') {
                    std::set<int>::iterator next = current;
                    for (int i = 0; i < move; ++i) {
                        if (++next == tableSet.end())
                            break;
                    }
                    
                    if (next != tableSet.end())
                        current = next;
                    else {
                        current = tableSet.end();
                        --current;
                    }
                }
                else {
                    std::set<int>::iterator next = current;
                    for (int i = 0; i < move; ++i) {
                        if (--next == tableSet.begin())
                            break;
                    }
                    current = next;
                }

            }

        }

        std::set<int>::iterator iter = tableSet.begin();
        for (; iter != tableSet.end(); ++iter) {
            answer[*iter] = 'O';
        }

        return answer;
    }
};