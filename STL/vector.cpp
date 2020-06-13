#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
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
	5.	�������� �������۽�, iterator������ ���ǰ� �ʿ��ϴ�. �̴� ��� �����̳ʿ� ����Ǵ� ����̴�.
		�߰������� ���� �����͸� ������ ��, �޸� �����۾��� ���־���Ѵ�. -> ����, ����Ʈ�����͸� ��õ
*/

/*
	push_back():			���ڷμ� �ʿ��� �ӽð�ü�� ���� �� ���� or �̵��� �Ͼ��. (������, ��������� ȣ��)
	emplace_back():			���ڷμ� �ʿ��� ��ü�� �����̳ʿ� �ٷ� �����Ѵ�. (������ or ��������� ȣ��)
	reserve():				()���� �� ������ ����ش�. -> ()������ �������Ҵ�(���������ȣ��)�� �����ش�.
	erase():				�������� ��, ���� iterator�� ��ȯ�Ѵ�. (�����ȿ��� �������۽� ���ǰ� �ʿ��ϴ�.)
	erase(remove(), end()):	vector�� remove()�� ������� �ʾ� Ư������ ���� �� ���� �̿� ���� ����Ѵ�.
							remove()�� �ش� ������ ���������� ������. -> �ǹ̾��� ������ �ڿ� ����� 
							�� ������ ������ ����Ű�� �ݺ��� ��ȯ. ������, �ǹ̾��� ���� ������ size�� ������ ����.
							����, erase()�� �̿��� remove() ��ȯ������ end()���� �����͸� ���� (capacity�� ���Ծ���)
*/


// ����ִ� v�� String 20���� �߰��϶�
// String�� ���� uid(10, 70)���� �ʱ�ȭ
// String�� ���ڸ� ������������ ����
// v�� String�� ���� ������������ ����
// ����� ȭ�鿡 ���
void solution1()
{
	vector<String> v{};		// ���� ��ü�� ������ ���°� �ƴ�

	default_random_engine dre;
	uniform_int_distribution<> uid{ 10,	20 };

	for (int i = 0; i < 20; ++i)
		v.emplace_back(uid(dre));

	sort(v.begin(), v.end(), [](const String& left, const String& right)
		{
			return left.getP() < right.getP();
		});

	for (const auto& i : v)		// ��ȸ��� 1 (��õ)
		cout << i << endl;

	cout << endl;

	sort(v.begin(), v.end());	// Ŭ���� ���� <������ �����ε� ������ ����° ���� ���ʿ�.

	for (auto i = v.cbegin(); i != v.cend(); ++i)	// ��ȸ��� 2
		cout << *i << endl;	// �ݺ��ڴ� �����͸� ��ȯ�ϱ� ������ �������� ���� �����;���.
}

// �Է��ڷ� - Ű����
// ����ڷ� - ȭ��
// Ű���忡�� string�� �Է¹޾� ���� �� ȭ�� ����϶�.
void solution2()
{
	vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };	// (Ű���� ����, Ű���� ��)

	sort(v.begin(), v.end());

	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
}

// �ҽ�.cpp���� e�� ������ ����� e���¼ҽ�.cpp�� �����϶�
// remove_if�� e�� �����Ѵ�. (erase���� if����� ����.)
// ������� ó���ϱ����� istreambuf_iterator, ostreambuf_ierator�� ���
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

// ������ �������۽� ���ǻ��׿� ���ؼ� �˾ƺ���.
// �ε��� ������ �����ϴ� ���� �ݺ��� ������ �����ϴ� ��찡 �ִ�.
// ������������� ++������ ����ڰ� ��Ʈ���� �� �����Ƿ� ����ϸ� �ȵȴ�.
void solution4()
{
	vector<int> v1{};
	vector<int> v2{};

	for (int i = 0; i < 10; ++i)
	{
		v1.emplace_back(i);
		v2.emplace_back(i);
	}

	//	index
	for (int i = 0; i < v1.size();)
	{
		if (v1[i] % 2 == 0) v1.erase(v1.begin() + i);	// v1.begin()�� ���ŵȴ�. ������ iterator�� ���� ���� ����.
		else ++i;										// ++i�� index�� ���Ѵ�.
	}													// ����, erase()�� ��ȯ�Ǵ� ���� iterator�� ���ʿ䰡 ����.
	//	iterator
	for (auto i = v2.begin(); i < v2.end();)
	{
		if (*i % 2 == 0) i = v2.erase(i);				// i�� ���Ծ��ϸ�, ������ iterator�� �� ������Ѵ�. (����)
		else ++i;										// ++i�� iterator�� ���Ѵ�.
	}													// ����, erase()�� ��ȯ�Ǵ� ���� iterator�� �˾ƾ��Ѵ�.

	for (const auto& i : v1) cout << i << " ";
	cout << endl;
	for (const auto& i : v2) cout << i << " ";
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
	//solution4();
}