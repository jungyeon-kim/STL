#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// binary_search: "정렬되어 있는" begin에서 end중 특정 조건이나 값을 만족할 경우 true를 반환 (이진탐색)

// 기본적으로 <연산자를 사용하며 ==연산자 대신 !(a < b) && !(b < a)과 같은 식으로 같은지 여부를 판단한다.

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	sort(v.begin(), v.end());
	bool p = binary_search(v.begin(), v.end(), 5);

	if (p)
		cout << "존재" << endl;
	else
		cout << "존재안함" << endl;
}