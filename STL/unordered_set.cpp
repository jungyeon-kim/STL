#include <iostream>
#include <unordered_set>

using namespace std;

/*
	비정렬 연관 컨테이너 "unordered_set"	-> 동적 해시테이블
	사용처:	정렬될 필요가 없고 삽입, 삭제, 탐색에 대한 고른 성능이 필요할 경우
*/

/*
	1.	삭입, 삭제, 접근 성능이 평균적으로 O(1)이다.
	2.	정렬되지 않는다는 것을 제외하고는 set과 같다.
*/

int main()
{
	unordered_multiset<int> us{};

	for (int i = 0; i < 64; ++i)
		us.emplace(100);

	for (int i = 0; i < us.bucket_count(); ++i)
	{
		cout << "[" << i << "]";

		if (us.bucket_size(i))
		{
			cout << " - ";
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << *p << " ";
		}

		cout << endl;
	}
}