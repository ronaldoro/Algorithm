// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "maxSumSubmatrix.h"

int main() {

	vector<vector<int>> test = { {1,0,1},{0,-2,3} };
	int k = 2;

	Solution s;
	s.maxSumSubmatrix(test, k);

	return 1;
}