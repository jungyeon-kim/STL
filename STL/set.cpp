#include <iostream>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

/*
	연관 컨테이너 "set"
	사용처:	정렬된 저장상태와 삽입, 삭제, 탐색에 대한 고른 성능이 필요할 경우
*/

/*
	1.	삽입, 삭제, 접근 성능이 모두 O(logN)이다.
		삽입, 삭제:	vector보단 빠르고, list보단 느리다.
		탐색:		vector보단 느리고, list보단 빠르다.
	2.	key가 원소이며 중복이 불가하다. (multiset은 가능)
	3.	항목이 저장될 때, 순서를 가진다. (default가 less여서 오름차순으로 정렬된다. 내림차순은 greater)
	4.	map과 마찬가지로 내장함수로 find()가 존재한다.
	5.	map과 다르게 []연산자가 지원되지 않는다.
	6.	임의로 내부 값을 수정할 수 없다. -> 모든 타입이 항상 const이다.
*/


// "alice2.txt"를 multiset으로 읽어온다.
// 단어의 사용횟수를 내림차순으로 화면에 출력하라
void solution1()
{
	ifstream in{ "alice2.txt" };
	multiset<string> words{ istream_iterator<string>(in), istream_iterator<string>() };
	map<int, string, greater<int>> words2{};

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		words2.emplace(words.count(*i), *i);

	for (const auto& i : words2)
		cout << i.first << " " << i.second << endl;
}

int main()
{
	solution1();
}