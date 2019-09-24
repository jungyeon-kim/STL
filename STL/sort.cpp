#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <iterator>
#include <string>
#include "String.h"
#include "Iter.h"

using namespace std;
using namespace std::chrono;

// ---------------------------------------------------------------------------------------------
// 정렬 알고리즘
// sort:			일반 정렬   
// stable_sort:		원소의 순서를 유지하며 정렬
// partial_sort:	부분 정렬
// nth_element:		두번째 인자를 기준으로 조건에 맞는 원소는 좌측, 그렇지 않은 원소는 우측에 정렬
//					-> 완벽한 정렬이 아님
// partition:		조건을 만족하는 구간을 좌측으로 그렇지않은 구간을 우측으로 나눔
//					-> 조건을 만족하는 구간 마지막 원소의 다음 iterator를 반환
// is_sorted:		정렬된 상태인지 검사
// merge:			합친다. (정렬된 상태라면 그 상태를 유지)
// ---------------------------------------------------------------------------------------------

constexpr int MAX{ 1000000 };

// 함수객체
class FO
{
public:
	bool operator()(const int& left, const int& right) const
	{
		return left > right;
	}
};

// 함수
bool F(const int& left, const int& right)
{
	return left > right;
}

// 각 케이스별 정렬속도 테스트
void testSort1()
{
	vector<int> v{};

	v.reserve(MAX);

	for (int i = 0; i < MAX; ++i)
		v.emplace_back(i);

	{
		cout << "< sort에 람다 사용 > ";
		random_shuffle(v.begin(), v.end());
		auto begin = chrono::steady_clock::now();

		sort(v.begin(), v.end(), [](const int& left, const int& right)
			{
				return left > right;
			});

		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		cout << "< sort에 함수객체 사용 > ";
		random_shuffle(v.begin(), v.end());
		auto begin = chrono::steady_clock::now();

		sort(v.begin(), v.end(), FO());

		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		cout << "< sort에 함수 사용 > ";
		random_shuffle(v.begin(), v.end());
		auto begin = chrono::steady_clock::now();

		sort(v.begin(), v.end(), F);

		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
}

// sort, stable_sort
void testSort2()
{
	vector<String> v{
		5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1,
		5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1,
		5, 5, 5, 5, 5, 1
	};
	vector<String> v1{ v };
	vector<String> v2{ v };

	cout << "<원본 자료>" << endl;
	for (const String& s : v)
		cout << s << "\t";
	cout << endl;

	sort(v1.begin(), v1.end());
	cout << "<sort>" << endl;
	for (const String& s : v1)
		cout << s << "\t";
	cout << endl;

	stable_sort(v2.begin(), v2.end());
	cout << "<stable_sort>" << endl;
	for (const String& s : v2)
		cout << s << "\t";
	cout << endl;
}

// partial_sort, nth_element, partition
void testSort3()
{
	vector<String> v{};
	for (int i = 0; i < 20; ++i)
		v.emplace_back(i + 1);
	random_shuffle(v.begin(), v.end());		// 랜덤으로 섞는다.

	cout << "<원본 자료>" << endl;
	for (const String& s : v)
		cout << '[' << s.getNum() << ']' << s << endl;
	cout << endl;

	cout << "<partial_sort>" << endl;
	partial_sort(v.begin(), v.begin() + 10, v.end());
	for (const String& s : v)
		cout << '[' << s.getNum() << ']' << s << endl;
	cout << endl;

	random_shuffle(v.begin(), v.end());

	cout << "<nth_elementt>" << endl;
	nth_element(v.begin(), v.begin() + 10, v.end(), [](const String& lhs, const String& rhs)
		{
			return lhs.getNum() > rhs.getNum();
		});	// 운좋게 완벽히 정렬됨
	for (const String& s : v)
		cout << '[' << s.getNum() << ']' << s << endl;
	cout << endl;

	random_shuffle(v.begin(), v.end());

	cout << "<partition>" << endl;
	auto p = partition(v.begin(), v.end(), [](const String& rhs)
		{
			return rhs.getNum() % 2 == 1;
		});
	for (const String& s : v)
		cout << '[' << s.getNum() << ']' << s << endl;
	cout << endl;

	for (auto i = v.begin(); i != p; ++i)
		cout << '[' << i->getNum() << ']' << *i << endl;
}

// merge
void testSort4()
{
	vector<String> v{};
	for (int i = 0; i < 20; ++i)
		v.emplace_back(i + 1);
	random_shuffle(v.begin(), v.end());

	vector<String> v1{ v };
	vector<String> v2{};
	v2.reserve(v.size() + v1.size());

	merge(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));

	for (const auto& i : v2)
		cout << i << endl;
}

// alice.txt에서 z가 들어가는 문자열을 제외하고 화면에 출력하라
void solution1()
{
	ifstream in{ "alice.txt" };
	vector<string> v{ istream_iterator<string>(in), istream_iterator<string>() };

	auto p = partition(v.begin(), v.end(), [](const string& rhs)
		{
			auto p = find(rhs.begin(), rhs.end(), 'z');
			if (p != rhs.end())
				return 1;
			else
				return 0;
		});

	v = { v.begin(), p };

	for (const auto& i : v)
		cout << i << endl;
}

// 길이가 5인 원소가 있다면 몇번째있는지 모두 출력하라.
void solution2()
{
	vector<String> v{};
	v.reserve(100);

	for (int i = 0; i < 100; ++i)
		v.emplace_back(i % 10 + 1);

	auto p = find_if(v.begin(), v.end(), [](const String& rhs)
		{
			return rhs.getNum() == 5;
		});

	if (p == v.end()) cout << "길이가 5인 원소가 없습니다." << endl;
	while (p != v.end())
	{
		if (p->getNum() == 5) cout << distance(v.begin(), p + 1) << " 번째" << endl;
		++p;
	}
}

int main()
{
	//testSort1();
	//testSort2();
	testSort3();
	//testSort4();

	//solution1();
	//solution2();
}