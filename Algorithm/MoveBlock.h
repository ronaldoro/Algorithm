#include "algorithmHeader.h"
#pragma once
bool insertPos(queue<vector<int>>& que, vector<int> pos, set<vector<int>>& visited, int N) {
    if (visited.find(pos) == visited.end()) {
        if ((pos[0] == N - 1 && pos[1] == N - 1) || (pos[2] == N - 1 && pos[3] == N - 1)) {
            return true;
        }
        visited.insert(pos);
        que.push(pos);
    }

    return false;
}

int BFS(const vector<vector<int>>& board) {
    int result = 0;

    int N = board.size();

    set<vector<int>> visited;

    vector<int> pos = { 0,0,1,0 }; //x1,y1,x2,y2
    queue<vector<int>> que;
    que.push(pos);

    visited.insert(pos);
    bool check = false;
    while (que.empty() == false && !check) {
        int queSize = que.size();
        for (int i = 0; i < queSize; ++i) {
            vector<int> quePos = que.front();

            if (quePos[1] == quePos[3]) { //row
                if (quePos[0] > quePos[2]) {
                    int temp = quePos[2];
                    quePos[2] = quePos[0];
                    quePos[0] = temp;
                }

                if (quePos[1] + 1 < N &&
                    (board[quePos[1] + 1][quePos[0]] == 0 && board[quePos[1] + 1][quePos[2]] == 0)) {
                    //RotateDown
                    vector<int> pos = { quePos[0],quePos[1], quePos[0], quePos[1] + 1 };
                    check |= insertPos(que, pos, visited, N);

                    //RotateDown
                    pos = { quePos[2],quePos[3], quePos[2], quePos[3] + 1 };
                    check |= insertPos(que, pos, visited, N);

                    //MoveDown
                    pos = { quePos[0],quePos[1] + 1, quePos[2], quePos[3] + 1 };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[1] - 1 >= 0 &&
                    (board[quePos[1] - 1][quePos[0]] == 0 && board[quePos[1] - 1][quePos[2]] == 0)) {
                    //RotateUp
                    vector<int> pos = { quePos[0],quePos[1] - 1, quePos[0], quePos[1] };
                    check |= insertPos(que, pos, visited, N);

                    //RotateUp
                    pos = { quePos[2],quePos[3] - 1, quePos[2], quePos[3] };
                    check |= insertPos(que, pos, visited, N);

                    //moveUp
                    pos = { quePos[0],quePos[1] - 1, quePos[2], quePos[3] - 1 };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[2] + 1 < N && board[quePos[1]][quePos[2] + 1] == 0) {
                    //moveRight
                    vector<int> pos = { quePos[0] + 1,quePos[1], quePos[2] + 1, quePos[3] };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[0] - 1 >= 0 && board[quePos[1]][quePos[0] - 1] == 0) {
                    //moveLeft
                    vector<int> pos = { quePos[0] - 1,quePos[1], quePos[2] - 1, quePos[3] };
                    check |= insertPos(que, pos, visited, N);
                }

            }
            else { // col
                if (quePos[1] > quePos[3]) {
                    int temp = quePos[1];
                    quePos[1] = quePos[3];
                    quePos[3] = temp;
                }

                if (quePos[0] + 1 < N &&
                    (board[quePos[1]][quePos[0] + 1] == 0 && board[quePos[3]][quePos[2] + 1] == 0)) {

                    //rotate
                    vector<int> pos = { quePos[0],quePos[1], quePos[0] + 1, quePos[1] };
                    check |= insertPos(que, pos, visited, N);

                    //rotate
                    pos = { quePos[2],quePos[3], quePos[2] + 1, quePos[3] };
                    check |= insertPos(que, pos, visited, N);

                    //moveRight
                    pos = { quePos[0] + 1,quePos[1], quePos[2] + 1, quePos[3] };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[0] - 1 >= 0 &&
                    (board[quePos[1]][quePos[0] - 1] == 0 && board[quePos[3]][quePos[2] - 1] == 0)) {

                    //rotate
                    vector<int> pos = { quePos[0] - 1,quePos[1], quePos[0], quePos[1] };
                    check |= insertPos(que, pos, visited, N);

                    //rotate
                    pos = { quePos[2] - 1,quePos[3], quePos[2], quePos[3] };
                    check |= insertPos(que, pos, visited, N);

                    //moveLeft
                    pos = { quePos[0] - 1,quePos[1], quePos[2] - 1, quePos[3] };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[3] + 1 < N && board[quePos[3] + 1][quePos[2]] == 0) {
                    //moveDown
                    vector<int> pos = { quePos[0],quePos[1] + 1, quePos[2], quePos[3] + 1 };
                    check |= insertPos(que, pos, visited, N);
                }

                if (quePos[1] - 1 >= 0 && board[quePos[1] - 1][quePos[0]] == 0) {
                    //moveUp
                    vector<int> pos = { quePos[0],quePos[1] - 1, quePos[2], quePos[3] - 1 };
                    check |= insertPos(que, pos, visited, N);
                }
            }

            que.pop();
        }
        ++result;
    }

    return result;
}