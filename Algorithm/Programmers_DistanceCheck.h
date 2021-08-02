#include "algorithmHeader.h"
#pragma once


class Solution {
public:
    int check(vector<string> places) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (places[i][j] == 'P') {

                    //top
                    bool top = true;
                    if (i > 0) {
                        if (places[i - 1][j] == 'P') {
                            return 0;
                        }
                        else if (places[i - 1][j] == 'X') {
                            top = false;
                        }
                        else { //top-top
                            if (i > 1 && places[i - 2][j] == 'P')
                                return 0;
                        }
                    }

                    //right
                    bool right = true;
                    if (j < 4) {
                        if (places[i][j + 1] == 'P') {
                            return 0;
                        }
                        else if (places[i][j + 1] == 'X') {
                            right = false;
                        }
                        else { //right-right
                            if (j < 3 && places[i][j + 2] == 'P') {
                                return 0;
                            }
                        }
                    }

                    //bottom
                    bool bottom = true;
                    if (i < 4) {
                        if (places[i + 1][j] == 'P') {
                            return 0;
                        }
                        else if (places[i + 1][j] == 'X') {
                            bottom = false;
                        }
                        else { //bottom-bottom
                            if (i < 3 && places[i + 2][j] == 'P')
                                return 0;
                        }
                    }

                    //left
                    bool left = true;
                    if (j > 0) {
                        if (places[i][j - 1] == 'P') {
                            return 0;
                        }
                        else if (places[i][j - 1] == 'X') {
                            left = false;
                        }
                        else { //left-left
                            if (j > 1 && places[i][j - 2] == 'P')
                                return 0;
                        }
                    }

                    //top, right
                    if (i > 0 && j < 4) {
                        if (places[i - 1][j + 1] == 'P' && (top || right)) {
                            return 0;
                        }
                    }

                    //right, bottom
                    if (i < 4 && j < 4) {
                        if (places[i + 1][j + 1] == 'P' && (bottom || right)) {
                            return 0;
                        }
                    }

                    //left, bottom
                    if (i < 4 && j > 0) {
                        if (places[i + 1][j - 1] == 'P' && (bottom || left)) {
                            return 0;
                        }
                    }

                    //left, top
                    if (i > 0 && j > 0) {
                        if (places[i - 1][j - 1] == 'P' && (top || left)) {
                            return 0;
                        }
                    }
                }
            }
        }

        return 1;
    }

    vector<int> solution(vector<vector<string>> places) {
        vector<int> answer;

        for (int i = 0; i < places.size(); ++i) {
            answer.push_back(check(places[i]));
        }

        return answer;
    }
};