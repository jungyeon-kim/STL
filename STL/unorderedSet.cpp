#include <iostream>
#include <unordered_set>

using namespace std;

// ---------------------------------------------------------------------------------------------
// 정렬되지않은 연관컨테이너 "unorderedSet"
// ---------------------------------------------------------------------------------------------


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