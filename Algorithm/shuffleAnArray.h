#include "algorithmHeader.h"

class Solution {
public:
    vector<int> m_v;
    Solution(vector<int>& nums) {
        m_v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        return permu(m_v);
    }
    
    vector<int> permu(vector<int> v)
    {
        vector<int> ans=v;
        for (int i = ans.size() - 1; i >=0; i--)
            {
                int j = rand() % (i + 1);
                swap(ans[i],ans[j]);
            }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */