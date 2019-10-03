#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

// ---------------------------------------------------------------------------------------------
// �˻� �˰���
// find:			�־��� ���� ������ ù��° ���Ҹ� ã�´�.
// find_if:			�־��� ���ǰ� ������ ù��° ���Ҹ� ã�´�.
// find_if_not:		�־��� ���ǰ� �������� ���� ù��° ���Ҹ� ã�´�.
// find_first_of:	�ι�° ���ڷ� �޴� ������ ���ҵ��� ���� ó�� ��ġ�ϴ� ���� ã�´�.
// find_end:		���ӵ� ���ҳ� ������ ó�� ���� �� �ں��� ã�´�.
// search:			���ӵ� ���ҳ� ������ ó�� ���� ã�´�.
// search_n:		�־��� ���̳� ���ǿ� n�� ��ġ�� ���ҵ��� ã�´�.
// ---------------------------------------------------------------------------------------------

// ���׸� �Լ�: ���ø��� ���� Ÿ�����κ��� �����ο��� �Լ�
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
		cout << "ã�� ��: " << distance(v.begin(), p) + 1 << endl;
	else
		cout << "�� ����" << endl;
}

void testFind()
{
	ifstream in{ "alice.txt" };

	auto p = find(istream_iterator<string>(in), istream_iterator<string>(), "Alice");

	if (p == istream_iterator<string>())
		cout << "����" << endl;
	while (p != istream_iterator<string>())
	{
		if(*p == "Alice")
			cout << *p << " ã��" << endl;
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