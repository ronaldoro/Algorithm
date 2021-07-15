// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include "maxSumSubmatrix.h"
#include "triangleNumber.h"

int main() {

	vector<int> testCase = { 1,2,3,4,5,6 };
	//vector<int> testCase = { 2,2,3,4 };
	//vector<int> testCase = { 4,2,3,4 };

	Solution s;
	s.triangleNumber(testCase);
	//1 96 ,  2 96

	// 99(9 * 11) + 99(11*9)
	return 1;
}
