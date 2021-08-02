#include "algorithmHeader.h"

#pragma once

bool visited[1001] = {};
int roadsValue[1001][1001] = {};

class Programmers_MazeEscape {
public:
    bool checkTrap(int target, const vector<int>& traps) {
        for (int i = 0; i < traps.size(); ++i) {
            if (target == traps[i])
                return true;
        }
        return false;
    }

    int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
        int answer = 0;

        for (int i = 0; i < roads.size(); ++i) {
            if (roadsValue[roads[i][0]][roads[i][1]] == 0) {
                roadsValue[roads[i][0]][roads[i][1]] = roads[i][2];
            }
            else {
                roadsValue[roads[i][0]][roads[i][1]] = min(roadsValue[roads[i][0]][roads[i][1]], roads[i][2]);
            }
        }

        queue<pair<int, int>> bfs; //index, value
        bfs.push(make_pair(start, 0));

        bool find = false;
        while (bfs.empty() == false  && find == false) {

            int bfsSize = bfs.size();
            for (int i = 0; i < bfsSize; ++i) {
                int target = bfs.front().first;
                visited[target] = true;
                if (checkTrap(target, traps) == true) { //next is trap

                    for (int nextofTarget = 1; nextofTarget <= n; ++nextofTarget) {
                        int temp = roadsValue[target][nextofTarget];
                        roadsValue[target][nextofTarget] = roadsValue[nextofTarget][target];
                        roadsValue[nextofTarget][target] = temp;
                    }

                    for (int nextofTarget = 1; nextofTarget <= n; ++nextofTarget) {
                        if (roadsValue[target][nextofTarget] != 0) {

                            if (nextofTarget == end) {
                                answer = bfs.front().second + roadsValue[target][nextofTarget];
                                find = true;
                                break;
                            }

                            if (visited[nextofTarget] == false || checkTrap(nextofTarget, traps) == true) {
                                bfs.push(make_pair(nextofTarget, bfs.front().second + roadsValue[target][nextofTarget]));
                                visited[nextofTarget] = true;
                            }
                        }
                    }
                }
                else { //next is not trap
                    for (int nextofTarget = 1; nextofTarget <= n; ++nextofTarget) {
                        if (roadsValue[target][nextofTarget] != 0) {
                            if (visited[nextofTarget] == false) {
                                if (nextofTarget == end) {
                                    answer = bfs.front().second + roadsValue[nextofTarget][target];
                                    find = true;
                                    break;
                                }
                                bfs.push(make_pair(nextofTarget, bfs.front().second + roadsValue[target][nextofTarget]));
                            }
                        }
                    }
                }

                bfs.pop();
            }
        }


        return answer;
    }
};
