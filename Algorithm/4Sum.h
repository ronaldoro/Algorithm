#include "algorithmHeader.h"


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;

        if (nums.size() < 4)
            return output;

        sort(nums.begin(), nums.end());

        int temp = std::binary_search(nums.begin(), nums.end(), -1);

        for (size_t i = nums.size()-1; i > 2; --i) {
            for (size_t j = i-1; j > 1; --j) {
                for (size_t t = j - 1; t > 0; --t) {
                    int last = target - (nums[i] + nums[j] + nums[t]);
                    if (last < nums[t - 1]) {
                        if (std::binary_search(nums.begin(), nums.begin() + t - 1, last)) {
                            output.push_back({ last, nums[t], nums[j], nums[i]});
                        }
                    }
                    else if (last == nums[t - 1]) {
                        output.push_back({ last, nums[t], nums[j], nums[i] });
                    }
                    else {
                        break;
                    }
                    
                }
            }
        }
        sort(output.begin(), output.end());
        output.erase(unique(output.begin(), output.end()), output.end());

        return output;
    }
};