#include "algorithmHeader.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        if (dominoes.length() == 0)
            return dominoes;

        stack<int> Rstack;
        bool Rstate = false;

        for (int i = 0; i < dominoes.length(); ++i) {

            if (dominoes[i] == 'L') {
                int stackCnt = Rstack.size();
                if (Rstate == true) {
                    int leftCnt = stackCnt / 2;
                    while (leftCnt > 0) {
                        dominoes[Rstack.top()] = 'L';
                        Rstack.pop();
                        --leftCnt;
                    }

                    if (stackCnt % 2 == 1)
                        Rstack.pop();

                    int rightCnt = stackCnt / 2;
                    while (rightCnt > 0) {
                        dominoes[Rstack.top()] = 'R';
                        Rstack.pop();
                        --rightCnt;
                    }

                }
                else {
                    while (Rstack.empty() == false) {
                        dominoes[Rstack.top()] = 'L';
                        Rstack.pop();
                    }
                }
                Rstate = false;
            }
            else if (dominoes[i] == 'R') {
                while (Rstack.empty() == false) {
                    if (Rstate == true)
                        dominoes[Rstack.top()] = 'R';
                    Rstack.pop();
                }
                Rstate = true;
            }
            else { // dominoes[i] == '.'
                Rstack.push(i);
            }
        }

        while (Rstack.empty() == false && Rstate == true) {
            dominoes[Rstack.top()] = 'R';
            Rstack.pop();
        }

        return dominoes;

    }
};