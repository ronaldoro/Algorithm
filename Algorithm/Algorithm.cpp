// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include "maxSumSubmatrix.h"
#include "findLength.h"

int main() {

	vector<int> nums1 = { 1,2,3,2,1 };
	vector<int> nums2 = { 3,2,1,4,7 };

	Solution s;
	s.findLength(nums1, nums2);

	return 1;
}