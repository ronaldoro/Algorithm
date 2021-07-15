#include "algorithmHeader.h"


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;

        int result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 2; i < nums.size(); ++i) {
            for (int j = i-1; j > 0; --j) {
                vector<int>::iterator iter = upper_bound(nums.begin(), nums.begin()+j-1, nums[i]-nums[j]);
                if ((*iter) > nums[i] - nums[j]) {
                    result += j - (iter - nums.begin());
                }
            }
        }

        return result;
    }
};