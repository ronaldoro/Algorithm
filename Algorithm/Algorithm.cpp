// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include "maxSumSubmatrix.h"
//#include "MakingALargeIsland.h"

#include "jobScheduling.h"
using namespace std;

map<string, vector<string>> stringsMap;
vector<vector<string>> stringsParser = { {"0", "()"}, {"I"}, {"Z", "S", "7_"}, {"E", "B"}, {"A"}, {"Z", "S"},
                                        {"b", "G"}, {"T", "Y"}, {"B", "E3"}, {"g", "q"} };

void makeStrings(string word, int index, string makedString) {
    if (word.length() == index) {
        stringsMap[word].push_back(makedString);
        return;
    }
        
    int num = word[index] - 48;
    makeStrings(word, index + 1, makedString + to_string(num));
    for (int i = 0; i < stringsParser[num].size(); ++i) {
        //if (num == 2) {
        //    if (stringsParser[num][i] == "A") {
        //        continue;
        //    }
        //}
        //else if (num == 5) {

        //}
        //else if (num == 3) {

        //}
        //else if (num == 8) {

        //}

        makeStrings(word, index+1, makedString + stringsParser[num][i]);
    }

}

vector<int> solution(vector<string> numstrs, vector<string> words) {
    vector<int> answer;

    for (int i = 0; i < words.size(); ++i) {
        makeStrings(words[i], 0, "");
        int cnt = 0;
        for (int j = 0; j < numstrs.size(); ++j) {
            vector<string> stringsVector = stringsMap[words[i]];

			for (int vectorIndex = 0; vectorIndex < stringsVector.size(); ++vectorIndex) {
                if (numstrs[j].find(stringsVector[vectorIndex]) != string::npos) {
                    ++cnt;
                }
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}


int main() {
    //vector<string> numstrs = { "ZASSETE", "S4Z537B", "7_ASZEYB" };
    //vector<string> words = { "2455373", "425", "373", "378" };
	//solution(numstrs, words);

    vector<int> startTime = { 1,2,3,4,6 };
    vector<int> endTime = { 3,5,10,6,9 };
    vector<int> profit = { 20,20,100,70,60 };
    JobScheduling jobScheduling;
    jobScheduling.jobScheduling(startTime, endTime, profit);

	return 1;
}
