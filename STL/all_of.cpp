#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// all_of: begin���� end���� Ư�� ������ ������ ��� true�� ��ȯ

template <typename Iter, typename Pred>
bool myAll_of(Iter begin, Iter end, Pred ty)
{
	while (begin != end)
		if (!ty(*begin++))
			return false;
	return true;
}

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9 };

	//auto p = all_of(v.begin(), v.end(), [](int param)
	//{
	//	return param % 2 == 1;
	//});

	auto p = myAll_of(v.begin(), v.end(), [](int param)
		{
			return param % 2 == 1;
		});

	if (p) cout << "��� Ȧ��" << endl;
	else cout << "��� Ȧ�� �ƴ�" << endl;
}