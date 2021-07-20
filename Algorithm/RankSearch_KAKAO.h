#include "algorithmHeader.h"
#include <sstream>

class Solution {
public:
    vector<int> rankSearch(vector<string> info, vector<string> query) {
        vector<int> answer;

        vector<vector<
            vector<           // cpp(0), java(1), python(2)
            vector<           // b(0), f(1)
            vector<           // junior(0), senior(1)
            int>>>>> hash;   // food, score

        for (int i = 0; i < info.size(); ++i) {
            vector<string> splitString = split(info[i], ' ');


            vector<vector<int>> temp;
            if (splitString[3] == "chicken") {
                temp.push_back({ 0, stoi(splitString[4]) } );
            }
            else {
                temp.push_back({ 1, stoi(splitString[4]) });
            }

            vector<vector<vector<int>>> temp1;
            if (splitString[2] == "junior") {
                temp1.push_back(vector<vector<int>>());
            } else {
                //temp1.push_back({ 1, temp });
            }

            vector<pair<int, vector<pair<int, vector<pair<int, int>>>>>> temp2;
            if (splitString[1] == "backend") {
                temp2.push_back(make_pair(0, temp1));
            }
            else {
                temp2.push_back(make_pair(1, temp1));
            }

            vector<pair<int, vector<pair<int, vector<pair<int, vector<pair<int, int>>>>>>>> temp3;
            if (splitString[0] == "cpp") {
                temp3.push_back(make_pair(0, temp2));
            }
            else if (splitString[0] == "java") {
                temp3.push_back(make_pair(1, temp2));
            }
            else {
                temp3.push_back(make_pair(2, temp2));
            }

            hash.push_back(temp3);
        }

        for (int i = 0; i < query.size(); ++i) {
            vector<string> splitString = split(query[i], ' ');

            vector<int> index0 = {};
            if (splitString[0] == "cpp") {
                index0.push_back(0);
            }
            else if (splitString[0] == "java") {
                index0.push_back(1);
            }
            else if (splitString[0] == "python") {
                index0.push_back(1);
            }
            else {
                index0.push_back(0);
                index0.push_back(1);
                index0.push_back(2);
            }

            vector<int> index1 = {};
            if (splitString[0] == "backend") {
                index1.push_back(0);
            } else if (splitString[0] == "frontend") {
                index1.push_back(1);
            }
            else {
                index1.push_back(0);
                index1.push_back(1);
            }

            vector<int> index2 = {};
            if (splitString[0] == "junior") {
                index2.push_back(0);
            }
            else if (splitString[0] == "senior") {
                index2.push_back(1);
            }
            else {
                index2.push_back(0);
                index2.push_back(1);
            }

            vector<int> index3 = {};
            if (splitString[0] == "chicken") {
                index3.push_back(0);
            }
            else if (splitString[0] == "pizza") {
                index3.push_back(1);
            }
            else {
                index3.push_back(0);
                index3.push_back(1);
            }

            for (int idx0 = 0; idx0 < index0.size(); ++idx0) {
                for (int idx1 = 0; idx1 < index1.size(); ++idx1) {
                    for (int idx2 = 0; idx2 < index2.size(); ++idx2) {
                        for (int idx3 = 0; idx3 < index3.size(); ++idx3) {

                            for (int j = 0; j < hash.size(); ++j) {
                                //hash[j][idx0].second.size() > 0 ? ;
                                    //second[idx1].second[idx2].second[idx3].second;
                            }


                        }
                    }
                }
            }
         
        }

        vector<vector<int>> test = { {1,5}, {1,2}, {1,4} , {1,3} , {1,3} };
        sort(test.begin(), test.end());





        return answer;
    }

    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str);
        string temp;

        while (getline(ss, temp, delimiter)) {
            internal.push_back(temp);
        }

        return internal;
    }
};