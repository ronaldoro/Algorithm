// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include "maxSumSubmatrix.h"
#include "4Sum.h"

int main() {

	vector<int> testCase = { 2,2,2,2,2 };
	//vector<int> testCase = { 2,2,3,4 };
	//vector<int> testCase = { 4,2,3,4 };

	Solution s;
	s.fourSum(testCase, 8);

	return 1;
}
