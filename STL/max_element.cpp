#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
	max_element:	begin에서 end중 최댓값(사용자 정의 가능)을 갖는 원소의 iterator를 반환
	min_element:	max_element와 반대
	minmax_element:	최솟값과 최댓값을 차고 그 둘을 묶어서 pair타입으로 반환
*/


int main()
{
	vector<string> v{};
	string s{};

	for (int i = 0; i < 10; ++i)
	{
		s += "*";
		v.emplace_back(s);
	}

	auto p = max_element(v.begin(), v.end());

	cout << *p << endl;
}