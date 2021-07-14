#include "algorithmHeader.h"

class Solution {
public:
#define MOD 1000000007
    // To do
    //// dp[i] = number of ways to decode the substring(0,i-1)
    //int numDecodings(string s) {
    //    vector<double> dp(s.length() + 1, 0);
    //    if (s[0] == '0') // no ways to decode
    //        return 0;
    //    double prev_two = 1; // base case
    //    double prev_one = (s[0] == '*') ? 9 : 1;
    //    double ans = prev_one;
    //    for (double i = 2; i <= s.length(); i++) {
    //        double curr_ans = 0;
    //        char curr = s[i - 1], prev = s[i - 2];
    //        // introducing first barrier like (12)(3)
    //        if (curr == '*')
    //            curr_ans = (curr_ans + (9 * prev_one) % MOD) % MOD;
    //        else if (curr != '0')
    //            curr_ans = (curr_ans + prev_one) % MOD;

    //        // introducing second barrier like (1)(23)
    //        if (prev == '*') {
    //            if (curr == '*')
    //                curr_ans = (curr_ans + (15 * prev_two) % MOD) % MOD;
    //            else if (curr <= '6')
    //                curr_ans = (curr_ans + (2 * prev_two) % MOD) % MOD;
    //            else
    //                curr_ans = (curr_ans + prev_two) % MOD;
    //        }
    //        else if (prev == '1') {
    //            if (curr == '*')
    //                curr_ans = (curr_ans + (9 * prev_two) % MOD) % MOD;
    //            else
    //                curr_ans = (curr_ans + prev_two) % MOD;
    //        }
    //        else if (prev == '2') {
    //            if (curr == '*')
    //                curr_ans = (curr_ans + (6 * prev_two) % MOD) % MOD;
    //            else if (curr <= '6')
    //                curr_ans = (curr_ans + prev_two) % MOD;
    //        }
    //        ans = curr_ans;
    //        prev_two = prev_one;
    //        prev_one = curr_ans;
    //    }
    //    return (int)ans;
    //}
};