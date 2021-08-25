#include "algorithmHeader.h"

#pragma once
class JudgeSquareSum
{
public:
    bool judgeSquareSum(int c) {
        bool result = false;
        int left = 0;
        int right = 1;

        while (true) {
            double value = right * right;
            if (value < c) {
                ++right;
            }
            else if (value == c) {
                return true;
            }
            else {
                break;
            }
        }

        while (left <= right) {
            while (true) {
                double value = left * left + right * right;
                if (value < c) {
                    ++left;
                }
                else if (value == c) {
                    return true;
                }
                else {
                    break;
                }
            }
            --right;
        }

        return result;
    }
};

