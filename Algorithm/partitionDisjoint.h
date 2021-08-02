#include "algorithmHeader.h"
#pragma once

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> minDp(nums.size());
        minDp[nums.size() - 1] = nums[nums.size() - 1];
        int min = minDp[nums.size() - 1];

        for (int i = nums.size() - 2; i > 0; --i) {
            if (min > nums[i]) {
                minDp[i] = nums[i];
                min = nums[i];
            }
            else {
                minDp[i] = min;
            }
        }

        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (minDp[i] >= max)
                return i;

            if (nums[i] > max) {
                max = nums[i];
            }
        }

        return 0;
    }
};