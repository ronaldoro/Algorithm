#include "algorithmHeader.h"
#include <bitset>
#pragma once

class Solution {
public:
    int findIntegers(int n) {
        int result = 0;
        int consec = 3;

        //time Limitted
        for (int i = 0; i <= n; ++i) {
            bool con = false;
            while (consec <= i) {

                if ((consec & i) != consec) {
                    consec = consec << 1;
                }
                else {
                    con = true;
                    break;
                }
            }

            consec = 3;

            if (con == false)
                result++;
        }

        return result;

    }
};
