#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "String.h"

using namespace std;

// copy: ~부터 ~까지를 ~에 복제한다.

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