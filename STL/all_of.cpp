#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// all_of: begin부터 end까지 특정 조건을 만족할 경우 true를 반환

template <typename Iter, typename Pred>
bool myAll_of(Iter begin, Iter end, Pred ty)
{
	while (begin != end)
		if (!ty(*begin++))
			return false;
	return true;
}

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9 };

	//auto p = all_of(v.begin(), v.end(), [](int param)
	//{
	//	return param % 2 == 1;
	//});

	auto p = myAll_of(v.begin(), v.end(), [](int param)
		{
			return param % 2 == 1;
		});

	if (p) cout << "모두 홀수" << endl;
	else cout << "모두 홀수 아님" << endl;
}