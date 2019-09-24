#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

	// 1.
	// std::string ��ü�� �� �迭�� �����ϰ� �ڽ��� ������ �ܾ��� �ʱ�ȭ�� ��
	// �ݺ��ڸ� ����� �迭�� ������ ���ٿ� �ϳ��� ���.

	/*list<string> a = { "aaa", "bbb", "ccc", "ddd", "eee" };
	auto p = begin(a);

	while (p != end(a))
	{
		cout << *p++ << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// 2.
	// �� ���ҿ� transform�� ������ ��� ������ *�� �ٲ� ȭ�鿡 ���.

	string a[5] = { "spring", "summer", "winter", "and", "fall" };

	//transform(������, ������, ����, ���)
	transform(begin(a), end(a), ostream_iterator<string>(cout, " "), [](string& str)
		{
			for (char& c : str)
			{
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
					c = '*';
			}
			return str;
		});
}