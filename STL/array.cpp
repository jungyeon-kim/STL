#include <iostream>
#include <array>
#include "String.h"

using namespace std;

// ---------------------------------------------------------------------------------------------
// 순차컨테이너 "array"
// 	- 원소의 개수가 고정되어 있을 때 효율적이다.
// 	- array<타입, 개수> 변수
// 	- 일반 배열 <<< array 컨테이너
// ---------------------------------------------------------------------------------------------


int main()
{
	array<String, 5> arr{ 10, 20, 30, 40, 50 };

	sort(begin(arr), end(arr), [](const String& left, const String& right)
		{
			return left.getP() < right.getP();
		});

	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;	// iterator은 포인터와 비슷하기때문에 역참조로 출력해야 '값'이 나옴
	}
}