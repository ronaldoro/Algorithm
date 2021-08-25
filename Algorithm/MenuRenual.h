#include "algorithmHeader.h"
#pragma once


class MenuRenual
{
public:
    int coursesMax[11] = {};

    void makeMenu(map<string, int>& menuMap, string menu, string orders) {
        if (orders.length() < 1) {
            if (menu.length() > 1) {
                menuMap[menu]++;
                coursesMax[menu.length()] = max(coursesMax[menu.length()], menuMap[menu]);
            }
            return;
        }

        if (menu.length() > 1) {
            menuMap[menu]++;
            coursesMax[menu.length()] = max(coursesMax[menu.length()], menuMap[menu]);
        }

        for (int i = 0; i < orders.length(); ++i) {
            string order = orders;
            string temp = "";
            temp += order[i];
            makeMenu(menuMap, menu + temp, order.substr(i+1));
        }
    }

    vector<string> solution(vector<string> orders, vector<int> course) {
        vector<string> answer;

        map<string, int> menuMap;
        for (int i = 0; i < orders.size(); ++i) {
            for (int j = 0; j < orders[i].length(); ++j) {
                string order = orders[i];
                string temp = "";
                temp += order[j];
                makeMenu(menuMap, temp, order.substr(j+1));
            }
        }

        bool courseCheck[11] = {};
        for (int i = 0; i < course.size(); ++i) {
            courseCheck[course[i]] = true;
        }

        map<string, int>::iterator iter = menuMap.begin();
        for (; iter != menuMap.end(); ++iter) {
            int length = iter->first.length();
            if (courseCheck[length] == true && coursesMax[length] > 1 && 
                iter->second >= coursesMax[length]) {
                answer.push_back(iter->first);
            }

        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};

