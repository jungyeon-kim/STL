#include <iostream>
#include <array>
#include "String.h"

using namespace std;

/*
	순차 컨테이너 "array"
	사용처:	사용하려는 원소의 개수가 고정되어있는 경우
*/

/*
	1.	연속된 메모리이기 때문에, index에 즉시 접근이 가능해 O(1)로 접근 성능이 좋다.
	2.	삽입, 삭제 기능을 지원하지 않는다.
*/


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