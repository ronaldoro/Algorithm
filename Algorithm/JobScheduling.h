#include "algorithmHeader.h"
#pragma once

class JobScheduling {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, int>> endTimes;

        for (int i = 0; i < startTime.size(); ++i) {
            endTimes.push_back(make_pair(endTime[i], i));
        }

        sort(endTimes.begin(), endTimes.end());

        map<int, int> dp = { {0,0} };
        for (int i = 0; i < endTimes.size(); ++i) {
            auto it = --dp.upper_bound(startTime[endTimes[i].second]);
            dp[endTimes[i].first] = max(profit[endTimes[i].second]+it->second, dp.rbegin()->second);
        }

        return dp.rbegin()->second;
    }
};