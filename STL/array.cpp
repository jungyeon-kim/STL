#include <iostream>
#include <array>
#include "String.h"

using namespace std;

// ---------------------------------------------------------------------------------------------
// ���������̳� "array"
// 	- ������ ������ �����Ǿ� ���� �� ȿ�����̴�.
// 	- array<Ÿ��, ����> ����
// 	- �Ϲ� �迭 <<< array �����̳�
// ---------------------------------------------------------------------------------------------


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