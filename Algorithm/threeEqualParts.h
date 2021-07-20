#include "algorithmHeader.h"
#include <bitset>

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> output;

        if (arr.size() < 3)
            return output;
        
        int left = 0;
        int right = arr.size() - 1;

        bitset<30001> parts1(arr[0]);
        bitset<30001> parts2;
        bitset<30001> parts3(arr[arr.size()-1]);

        int bitIndex = right-2;
        for (int i = left + 1; i < right; ++i) {
            parts2.set(bitIndex, arr[i]);
            --bitIndex;
        }
        int part2Cnt = arr.size() - 3;

        while (left < right-2) {

            if(parts1 == parts3){
                if (parts1 == parts2) {
                    output.push_back(left);
                    output.push_back(right);
                    return output;
                }
                else {
                    --right;
                    parts3.set(arr.size() - right - 1, arr[right]);
                    parts2 = parts2 >> 1;
                }
            } else if (parts1.count() <= parts3.count()) {
                ++left;
                parts1 = parts1 << 1;
                parts1.set(0, arr[left]);
                parts2 = parts2.set(part2Cnt, false);
            } else /*if (parts1.to_ulong() > parts3.to_ulong())*/ {
                --right;
                parts3.set(arr.size() - right - 1, arr[right]);
                parts2 = parts2 >> 1;
            }

            --part2Cnt;
        }

        if (parts1 == parts2 && parts1 == parts3) {
            output.push_back(left);
            output.push_back(right);
            return output;
        }

        output.push_back(-1);
        output.push_back(-1);
        return output;
    }
};