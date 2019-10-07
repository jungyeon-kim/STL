#include <iostream>
#include <deque>
#include <fstream>
#include <iterator>
#include "String.h"

using namespace std;

/*
	순차 컨테이너 "deque"
	사용처:	앞쪽과 뒤쪽 모두 출입구로 사용해야하는 경우
			실제로 활용할 일은 거의 없음
*/

/*
	1.	vector와 기능은 똑같지만, 차이라면 앞쪽과 뒤쪽 모두를 출입구로 삼을 수 있다.
	2.	vector와 다르게 deque의 메모리 블럭은 분할되어 있다. -> 편리한 대신 여러 방면에서 속도가 더 느리다.
*/


// 소스.cpp를 불러와서 cmd창에 역순으로 출력하라

void solution1()
{
	ifstream in{ "소스.cpp" };

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

	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), front_inserter(d));	// in의 시작부터 끝까지 d에 하나씩 앞으로 삽입한다.
	copy(d.begin(), d.end(), ostreambuf_iterator<char>(cout));
}

int main()
{
	solution1();
}