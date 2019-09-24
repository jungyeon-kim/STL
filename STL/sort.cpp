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
// ���� �˰���
// sort:			�Ϲ� ����   
// stable_sort:		������ ������ �����ϸ� ����
// partial_sort:	�κ� ����
// nth_element:		�ι�° ���ڸ� �������� ���ǿ� �´� ���Ҵ� ����, �׷��� ���� ���Ҵ� ������ ����
//					-> �Ϻ��� ������ �ƴ�
// partition:		������ �����ϴ� ������ �������� �׷������� ������ �������� ����
//					-> ������ �����ϴ� ���� ������ ������ ���� iterator�� ��ȯ
// is_sorted:		���ĵ� �������� �˻�
// merge:			��ģ��. (���ĵ� ���¶�� �� ���¸� ����)
// ---------------------------------------------------------------------------------------------

constexpr int MAX{ 1000000 };

// �Լ���ü
class FO
{
public:
	bool operator()(const int& left, const int& right) const
	{
		return left > right;
	}
};

// �Լ�
bool F(const int& left, const int& right)
{
	return left > right;
}

// �� ���̽��� ���ļӵ� �׽�Ʈ
void testSort1()
{
	vector<int> v{};

	v.reserve(MAX);

	for (int i = 0; i < MAX; ++i)
		v.emplace_back(i);

	{
		cout << "< sort�� ���� ��� > ";
		random_shuffle(v.begin(), v.end());
		auto begin = chrono::steady_clock::now();

		sort(v.begin(), v.end(), [](const int& left, const int& right)
			{
				return left > right;
			});

		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		cout << "< sort�� �Լ���ü ��� > ";
		random_shuffle(v.begin(), v.end());
		auto begin = chrono::steady_clock::now();

		sort(v.begin(), v.end(), FO());

		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		cout << "< sort�� �Լ� ��� > ";
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

	cout << "<���� �ڷ�>" << endl;
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
	random_shuffle(v.begin(), v.end());		// �������� ���´�.

	cout << "<���� �ڷ�>" << endl;
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
		});	// ������ �Ϻ��� ���ĵ�
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

// alice.txt���� z�� ���� ���ڿ��� �����ϰ� ȭ�鿡 ����϶�
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

// ���̰� 5�� ���Ұ� �ִٸ� ���°�ִ��� ��� ����϶�.
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

	if (p == v.end()) cout << "���̰� 5�� ���Ұ� �����ϴ�." << endl;
	while (p != v.end())
	{
		if (p->getNum() == 5) cout << distance(v.begin(), p + 1) << " ��°" << endl;
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