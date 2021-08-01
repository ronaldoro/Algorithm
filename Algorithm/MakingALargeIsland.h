#include "algorithmHeader.h"
#pragma once


class Solution {
public:
    vector<vector<int*>> islandSizes;

    ~Solution() {
        vector<int*> islandSize;
        for (int i = 0; i < islandSizes.size(); ++i) {
            for (int j = 0; j < islandSizes.size(); ++j) {
                if (islandSizes[i][j] != NULL)
                    islandSize.push_back(islandSizes[i][j]);
            }

        }

        sort(islandSize.begin(), islandSize.end());
        islandSize.erase(unique(islandSize.begin(), islandSize.end()), islandSize.end());

        for (int i = 0; i < islandSize.size(); ++i) {
            delete islandSize[i];
            islandSize[i] = NULL;
        }
    }

    void search(vector<vector<int>>& grid, int* size, int y, int x) {
        ++(*size);
        islandSizes[y][x] = size;

        if (y > 0 && grid[y-1][x] == 1 && islandSizes[y-1][x] == NULL) {
            search(grid, size, y - 1, x);
        }

        if (x > 0 && grid[y][x-1] == 1 && islandSizes[y][x-1] == NULL) {
            search(grid, size, y, x - 1);
        }

        if (y < grid.size() - 1 && grid[y + 1][x] == 1 && islandSizes[y + 1][x] == NULL) {
            search(grid, size, y + 1, x);
        }

        if (x < grid[0].size() - 1 && grid[y][x + 1] == 1 && islandSizes[y][x + 1] == NULL) {
            search(grid, size, y, x + 1);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            vector<int*> islandSize;
            for (int j = 0; j < grid[0].size(); ++j) {
                islandSize.push_back(NULL);
            }
            islandSizes.push_back(islandSize);
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && islandSizes[i][j] == NULL) {
                    int* tempSize = new int();
                    search(grid, tempSize, i, j);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    int temp = 1;
                    vector<int*> directios;
                    if (i > 0 && islandSizes[i - 1][j] != NULL) {
                        directios.push_back(islandSizes[i - 1][j]);
                    }

                    if (j > 0 && islandSizes[i][j - 1] != NULL) {
                        directios.push_back(islandSizes[i][j - 1]);
                    }

                    if (i < grid.size() - 1 && islandSizes[i + 1][j] != NULL) {
                        directios.push_back(islandSizes[i + 1][j]);
                    }

                    if (j < grid[0].size() - 1 && islandSizes[i][j + 1] != NULL) {
                        directios.push_back(islandSizes[i][j + 1]);
                    }

                    sort(directios.begin(), directios.end());
                    directios.erase(unique(directios.begin(), directios.end()), directios.end());

                    for (int i = 0; i < directios.size(); ++i)
                        temp += *directios[i];

                    result = max(result, temp);
                }
                else {
                    result = max(result, *islandSizes[i][j]);
                }
            }
        }

        return result;
    }
};