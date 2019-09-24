#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// count:		begin부터 end까지 특정 값의 개수를 반환
// count_if:	begin부터 end까지 특정 조건을 만족하는 값의 개수를 반환

// 제네릭 함수: 템플릿에 의해 타입으로부터 자유로워진 함수
template <typename Iter, typename Pred>
size_t myCount_if(Iter begin, Iter end, Pred ty)
{
	int cnt{};

	while (begin != end)
		if (ty(*begin++))
			++cnt;
	// begin++; 위 조건문에서 후위연산자로 ++을 해주고 있음. 따라서 불필요
	return cnt;
}

class X
{
public:
	bool operator()(int n) const
	{
		return (n % 2) == 1;
	}
};

int main()
{
	vector<int> v{};

	v.reserve(100);
	for (int i = 0; i < 100; ++i)
		v.emplace_back(i + 1);

	auto n = myCount_if(v.begin(), v.end(), [](int n)	// 람다 사용
		{
			return (n % 2) == 1;
		});
	// auto n = myCount_if(v.begin(), v.end(), X());	// 함수객체 사용

	cout << "홀수의 갯수: " << n << endl;
}