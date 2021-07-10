#include "algorithmHeader.h"

class Solution {
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(begin(stones), end(stones));

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int temp = x - y;
            if (temp > 0) {
                pq.push(temp);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
