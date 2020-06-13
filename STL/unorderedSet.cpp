#include <iostream>
#include <unordered_set>

using namespace std;

/*
	������ ���� �����̳� "unordered_set"	-> ���� �ؽ����̺�
	���ó:	���ĵ� �ʿ䰡 ���� ����, ����, Ž���� ���� �� ������ �ʿ��� ���
*/

/*
	1.	����, ����, ���� ������ ��������� O(1)�̴�.
	2.	���ĵ��� �ʴ´ٴ� ���� �����ϰ�� set�� ����.
*/

int main()
{
	unordered_multiset<int> us{};

	for (int i = 0; i < 64; ++i)
		us.emplace(100);

	for (int i = 0; i < us.bucket_count(); ++i)
	{
		cout << "[" << i << "]";

		if (us.bucket_size(i))
		{
			cout << " - ";
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << *p << " ";
		}

		cout << endl;
	}
}