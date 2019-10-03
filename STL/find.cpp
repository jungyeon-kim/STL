#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

// ---------------------------------------------------------------------------------------------
// 검색 알고리즘
// find:			주어진 값과 동일한 첫번째 원소를 찾는다.
// find_if:			주어진 조건과 동일한 첫번째 원소를 찾는다.
// find_if_not:		주어진 조건과 동일하지 않은 첫번째 원소를 찾는다.
// find_first_of:	두번째 인자로 받는 범위의 원소들중 가장 처음 일치하는 것을 찾는다.
// find_end:		연속된 원소나 조건의 처음 값을 맨 뒤부터 찾는다.
// search:			연속된 원소나 조건의 처음 값을 찾는다.
// search_n:		주어진 값이나 조건에 n번 겹치는 원소들을 찾는다.
// ---------------------------------------------------------------------------------------------

// 제네릭 함수: 템플릿에 의해 타입으로부터 자유로워진 함수
template <typename Iter, typename Value>
Iter myFind(Iter begin, Iter end, Value val)
{
	while (begin != end)
	{
		if (*begin == val)
			return begin;
		++begin;
	}

	return end;
}

void testMyFind()
{
	vector<int> v{};

	v.reserve(100);
	for (int i = 0; i < 100; ++i)
		v.emplace_back(i + 1);

	auto p = myFind(v.begin(), v.end(), 80);

	if (p != v.end())
		cout << "찾은 값: " << distance(v.begin(), p) + 1 << endl;
	else
		cout << "값 없음" << endl;
}

void testFind()
{
	ifstream in{ "alice.txt" };

	auto p = find(istream_iterator<string>(in), istream_iterator<string>(), "Alice");

	if (p == istream_iterator<string>())
		cout << "없음" << endl;
	while (p != istream_iterator<string>())
	{
		if(*p == "Alice")
			cout << *p << " 찾음" << endl;
		++p;
	};
}

void testFindFirstOf()
{
	ifstream in{ "alice.txt" };
	vector<string> v{ "this", "is", "mouse" };

	auto p = find_first_of(istream_iterator<string>(in), istream_iterator<string>(), v.begin(), v.end());

	if (p != istream_iterator<string>())
		cout << *p << endl;
}

void testSearch()
{
	ifstream in{ "alice.txt" };
	vector<string> vi{ istream_iterator<string>(in), istream_iterator<string>() };
	vector<string> v{ "It", "was", "all" };

	auto p = search(vi.begin(), vi.end(), v.begin(), v.end());

	if (p != vi.end())
	{
		cout << *p << endl;
		++p;
		cout << *p << endl;
		++p;
		cout << *p << endl;
	}
}

int main()
{
	//testMyFind();
	//testFind();
	//testFindFirstOf();
	testSearch();
}