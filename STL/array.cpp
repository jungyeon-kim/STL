#include <iostream>
#include <array>
#include "String.h"

using namespace std;

/*
	���� �����̳� "array"
	���ó:	����Ϸ��� ������ ������ �����Ǿ��ִ� ���
*/

/*
	1.	���ӵ� �޸��̱� ������, index�� ��� ������ ������ O(1)�� ���� ������ ����.
	2.	����, ���� ����� �������� �ʴ´�.
*/


int main()
{
	array<String, 5> arr{ 10, 20, 30, 40, 50 };

	sort(begin(arr), end(arr), [](const String& left, const String& right)
		{
			return left.getP() < right.getP();
		});

	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;	// iterator�� �����Ϳ� ����ϱ⶧���� �������� ����ؾ� '��'�� ����
	}
}