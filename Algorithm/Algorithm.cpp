// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include "maxSumSubmatrix.h"
#include "RankSearch_KAKAO.h"

int main() {

	vector<string> info = { "java backend junior pizza 150" };
	vector<string> query = { "- and - and - and - 150" };
	//vector<int> testCase = { 2,2,3,4 };
	//vector<int> testCase = { 4,2,3,4 };

	Solution s;
	s.rankSearch(info, query);

	return 1;
}
