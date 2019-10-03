#include <iostream>
#include <vector>
#include <random>
#include "String.h"

using namespace std;

/*
	���� �����̳� "vector"
	���ó:	����, ���� ���ɺ��� ���� ������ �߿��� ���
			�迭�� ����ϸ鼭 ũ�Ⱑ �������� Ŀ���ų� �پ�� ���
*/

/*
	1.	���ӵ� �޸��̱� ������, arrayó�� index�� ��� ������ ������ O(1)�� ���� ������ ����.
	2.  �ε��� ���� ���� ���԰� ������ ��� O(1)�� �ſ� ������. 
		������, �׿��� �ε��������� �ڿ� �ִ� ��� �ε������� �аų� ���� �۾��� �ؾ��ؼ� O(N-p)�� ������.
	3.  ���� ���� ������ ������ �� ū ����(����ũ���� 1.5��)�� ���Ҵ��Ѵ�.
	4.  ����Լ� -> size, capacity, data (ũ��, �Ҵ簡�ɰ���, ������ġ)
*/

/*
	push_back():			���ڷμ� �ʿ��� �ӽð�ü�� ���� �� �� ���簡 �Ͼ��. (������, �̵���������� ȣ��)
	emplace_back():			���ڷμ� �ʿ��� ��ü�� �����̳ʿ� �ٷ� �����Ѵ�. (������ ȣ��)
	reserve():				()���� �� ������ ����ش�. -> ()������ �������Ҵ�(���������ȣ��)�� �����ش�.
	erase(remove(), end()):	remove()�� �ش� ������ ���������� ������. -> �ǹ̾��� ������ �ڿ� ����� 
							�� ������ ������ ����Ű�� �ݺ��� ��ȯ -> erase()�� �ش� ������ 
							remove() ��ȯ������ end()���� �����͸� ���� (capacity�� ���Ծ���)
*/


// ����ִ� v�� String 20���� �߰��϶�
// String�� ���� uid(10, 70)���� �ʱ�ȭ
// String�� ���ڸ� ������������ ����
// v�� String�� ���� ������������ ����
// ����� ȭ�鿡 ���
#include <algorithm>

void solution1()
{
	vector<String> v{};	// ���� ��ü�� ������ ���°� �ƴ�

	default_random_engine dre;
	uniform_int_distribution<> uid{ 10,	20 };


	for (int i = 0; i < 20; ++i)
		v.emplace_back(uid(dre));

	sort(v.begin(), v.end(), [](const String& left, const String& right)
		{
			return left.getP() < right.getP();
		});

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << endl;
	}

	cout << endl;

	sort(v.begin(), v.end());	// Ŭ���� ���� <������ �����ε� ������ ����° ���� ���ʿ�.

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << endl;
	}
}

// �Է��ڷ� - Ű����
// ����ڷ� - ȭ��
// Ű���忡�� string�� �Է¹޾� ���� �� ȭ�� ����϶�.
#include <string>
#include <iterator>
#include <algorithm>

void solution2()
{
	vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };	// (Ű���� ����, Ű���� ��)

	sort(v.begin(), v.end());

	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
}

// �ҽ�.cpp���� e�� ������ ����� e���¼ҽ�.cpp�� �����϶�
// remove_if�� e�� �����Ѵ�.
// ������� ó���ϱ����� istreambuf_iterator, ostreambuf_ierator�� ���
#include <fstream>
#include <iterator>
#include <algorithm>

void solution3()
{
	ifstream in{ "�ҽ�.cpp" };
	ofstream out{ "e���¼ҽ�.cpp" };
	vector<char> v{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };

	auto p = remove_if(v.begin(), v.end(), [](const char& c)
		{
			return c == 'e';
		});
	v.erase(p, v.end());

	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));
}

// ������ ���ظ� �������� �Լ�.
void testVector()
{
	vector<String> v{};

	//v.reserve(1000);

	while (1)
	{
		cout << "������ ���� ����		-> " << v.size() << endl;
		cout << "���� �� �ִ� ������ ����	-> " << v.capacity() << endl;
		cout << "���Ұ� ����Ǿ��ִ� ��ġ	-> " << v.data() << endl;

		char c{};
		cin >> c;

		v.emplace_back(10);
	}
}

int main()
{
	testVector();
	//solution1();
	//solution2();
	//solution3();
}