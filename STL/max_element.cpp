#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
	max_element:	begin���� end�� �ִ�(����� ���� ����)�� ���� ������ iterator�� ��ȯ
	min_element:	max_element�� �ݴ�
	minmax_element:	�ּڰ��� �ִ��� ���� �� ���� ��� pairŸ������ ��ȯ
*/


int main()
{
	vector<string> v{};
	string s{};

	for (int i = 0; i < 10; ++i)
	{
		s += "*";
		v.emplace_back(s);
	}

	auto p = max_element(v.begin(), v.end());

	cout << *p << endl;
}