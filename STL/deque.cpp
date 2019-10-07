#include <iostream>
#include <deque>
#include <fstream>
#include <iterator>
#include "String.h"

using namespace std;

/*
	���� �����̳� "deque"
	���ó:	���ʰ� ���� ��� ���Ա��� ����ؾ��ϴ� ���
			������ Ȱ���� ���� ���� ����
*/

/*
	1.	vector�� ����� �Ȱ�����, ���̶�� ���ʰ� ���� ��θ� ���Ա��� ���� �� �ִ�.
	2.	vector�� �ٸ��� deque�� �޸� ���� ���ҵǾ� �ִ�. -> ���� ��� ���� ��鿡�� �ӵ��� �� ������.
*/


// �ҽ�.cpp�� �ҷ��ͼ� cmdâ�� �������� ����϶�

void solution1()
{
	ifstream in{ "�ҽ�.cpp" };

	// verson1
	//deque<char> d{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };

	//copy(d.rbegin(), d.rend(), ostreambuf_iterator<char>(cout));	// rbegin ~ rend == end ~ begin

	// verson2
	/*istreambuf_iterator<char> p(in);
	deque<char> d{};
	while (p != istreambuf_iterator<char>()) d.emplace_front(*p++);

	for (char i : d)
		cout << i;*/

		// verson3
	deque<char> d{};

	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), front_inserter(d));	// in�� ���ۺ��� ������ d�� �ϳ��� ������ �����Ѵ�.
	copy(d.begin(), d.end(), ostreambuf_iterator<char>(cout));
}

int main()
{
	solution1();
}