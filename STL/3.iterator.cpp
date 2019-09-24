#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

	// 1.
	// std::string 객체로 된 배열을 정의하고 자신이 선택한 단어들로 초기화한 후
	// 반복자를 사용해 배열의 내용을 한줄에 하나씩 출력.

	/*list<string> a = { "aaa", "bbb", "ccc", "ddd", "eee" };
	auto p = begin(a);

	while (p != end(a))
	{
		cout << *p++ << endl;
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// 2.
	// 각 원소에 transform을 적용해 모든 모음을 *로 바꿔 화면에 출력.

	string a[5] = { "spring", "summer", "winter", "and", "fall" };

	//transform(어디부터, 어디까지, 어디로, 어떻게)
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