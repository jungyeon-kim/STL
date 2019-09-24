#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "String.h"

using namespace std;

// copy 알고리즘 구현하기
// copy(어디부터, 어디까지, 어디에) -> 세 인자 모두 반복자 형태

template <typename T, typename U>
inline void myCopy(T begin, T end, U target)
{
	while (begin != end)
		* target++ = *begin++;
}

int main()
{
	vector<String> v = { 1, 2, 3, 4, 5 };
	vector<String> w;

	myCopy(v.begin(), v.end(), back_inserter(w));

	for (const auto& d : w)
		cout << d << endl;
}