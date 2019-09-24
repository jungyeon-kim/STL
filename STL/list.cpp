#include <iostream>
#include <list>
#include "String.h"

using namespace std;

// ---------------------------------------------------------------------------------------------
// ���������̳� "list"
// - ���Ի��� ���ۿ� ȿ�����̴�.
// - ���������θ� ��ȸ�ص� �ȴٸ� "forward_list"�� ����Ѵ�.
// - ���� �ϳ����� �� ū �޸𸮰� �ʿ��ϴ�.
// - remove(): vector�� �ٸ��� �����Լ��� �����Ѵ�. (remove �� erase ������ �ʾƵ� ��)
// - merge(): list�� ��ģ��. -> ���ĵ� list���� ��밡���ϴ�.
// - unique(): �ߺ��Ǵ� ���� �����.
// - splice(): ���ϴ� ������ ���´�.
// ---------------------------------------------------------------------------------------------


// �� ����Ʈ�� merge�Ͽ� �ߺ��Ǵ� ���� �����ϰ� ����϶�.
void solution1()
{
	list<String> lst1{ 3, 6, 7, 3, 2, 1, 5 };
	list<String> lst2{ 2, 4, 6, 8, 10 };

	lst1.sort();
	lst2.sort();
	lst1.merge(lst2);
	lst1.unique();

	cout << "-------------------------------------------" << endl;
	for (const String& i : lst1)
		cout << i << endl;
	cout << "-------------------------------------------" << endl;
	for (const String& i : lst2)
		cout << i << endl;
	cout << "-------------------------------------------" << endl;
}

// "�ҽ�.cpp" ������ �о��
// ���̼����� �����϶� -> ������� ���͸� �ᵵ������
// ���̰� 4�� �ܾ ���� ���� "����4.txt"�� �����϶� -> �߰����������� ����Ʈ�� �����
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

void solution2()
{
	ifstream in{ "�ҽ�.cpp" };
	ofstream out{ "����4.txt" };
	list<string> lst{ istream_iterator<string>(in), istream_iterator<string>() };

	lst.sort([](const string& lhs, const string& rhs)
		{
			return lhs.length() < rhs.length();
		});

	// ���̰� 4�� ��ġ, 5�� ��ġ�� ã�´�.
	auto pos4 = find_if(lst.begin(), lst.end(), [](const string& rhs)	// begin���� end���� ��ȸ�ϴ� ���̰� 4�� ���ڿ��� ������ ���� �����Ѵ�.
		{
			return rhs.length() == 4;
		});
	auto pos5 = find_if(lst.begin(), lst.end(), [](const string& rhs)
		{
			return rhs.length() == 5;
		});

	// ���� �Űܺ���
	list<string> lst4{};
	lst4.splice(lst4.begin(), lst, pos4, pos5);	// ���, ������, ������, ������
	copy(lst4.begin(), lst4.end(), ostream_iterator<string>(out, "\n"));	// out���Ͽ� ��ĭ�� ��鼭 ����
	copy(lst.begin(), lst.end(), ostream_iterator<string>(cout, "\n"));
}

int main()
{
	solution1();
	//solution2();
}