#include <iostream>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

// ---------------------------------------------------------------------------------------------
// 연관컨테이너 "set"
// 	- key가 원소 (key값 중복불가)
//	- multiset: 중복되는 key값을 가질수있다.
//	- map과 마찬가지로 내부함수로 find()가 존재한다.
//	- 저장할 원소의 개수가 많을수록 효율적이다.
//	- 임의로 내부 값을 수정할 수 없다. -> 모든 타입이 항상 const이다.
//	- default가 less여서 오름차순으로 정렬된다. (내림차순은 greater)
// ---------------------------------------------------------------------------------------------


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