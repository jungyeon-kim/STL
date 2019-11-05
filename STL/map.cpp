#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

/*
	연관 컨테이너 "map"
	사용처:	key와 value가 쌍을 이루고 삽입, 삭제, 탐색에 대한 고른 성능이 필요할 경우
*/

/*
	1.	삽입, 삭제, 탐색 성능이 모두 O(logN)이다.
		삽입, 삭제:	vector보단 빠르고, list보단 느리다.
		탐색:		vector보단 느리고, list보단 빠르다.
	2.	dictionary형태 -> key와 value가 한 쌍을 이루고 중복이 불가하다. (multimap은 가능)
		허나, multimap은 중복되는 key값이 존재할 수 있기때문에 []연산자를 지원하지 않는다.
	3.	항목이 저장될 때, key를 기준으로 순서를 가진다. (default가 less여서 오름차순으로 정렬된다. 내림차순은 greater)
	4.	일반 find()가 아닌 map에 내장된 find()를 사용한다. (이진탐색 알고리즘) -> O(log n)
	5.	배열의 인덱스(key 값)로 단순히 int형이 아닌 string같은 임의의 타입을 사용할 수 있다.
*/

/*
	insert():		객체를 생성해 컨테이너에 복사시키므로 key, value를 쌍으로 가지는 객체화(make_pair)를 시켜야 한다.
	emplace():		컨테이너 자체에 객체를 생성하므로 그룹핑(make_pair)이 필요없다.
	equal_range():	내장함수로 존재한다. (lower_bound()와 upper_bound() 또한 지원한다.)
	first:			key멤버에 접근가능
	second:			value멤버에 접근가능
	pair<T, U>:		두 데이터가 한 쌍을 이루게 해줌 -> make_pair()로 더 간단히 가능
					마찬가지로 first와 second가 존재한다.
*/


// 그룹이름을 입력하여 map에 존재할 경우 key, value를 출력하라
// map에 존재하지 않을경우 연관배열을 이용해 생성하라
void solution1()
{
	map<string, int> idols{};

	idols.insert(pair<string, int>("있지", 5));
	idols.insert(make_pair("방탄소년단", 7));
	idols.emplace("아이즈원", 12);
	idols.emplace("워너원", 11);

	while (1)
	{
		string name{};

		cout << "아이돌 명: ";
		cin >> name;

		auto p = idols.find(name);

		if (p != idols.end())
			cout << p->first << " " << p->second << endl;
		else
		{
			int num{};

			cout << "존재안함. 인원수 입력: ";
			cin >> num;

			idols[name] = num;	// key값 name의 value를 num으로 설정한다.
		}
	}
}


// 소스.cpp에 사용된 알파벳과 사용횟수를 출력하라
void solution2()
{
	map<char, int> words{};
	ifstream in{ "소스.cpp" };

	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
		words[*i]++;	// 연관배열: 변수[key] = value -> 해당 key의 value값을 1씩 더한다.

	for (const auto& i : words)
		cout << i.first << " " << i.second << endl;
}


// alice.txt에 사용된 단어를 사용횟수의 오름차순으로 출력하라
// 알파벳이 아닌 문자는 공백으로 처리

void solution3()
{
	map<string, int> words{};
	multimap<int, string> isMap{};
	ifstream inOld{ "alice.txt" };
	ofstream out{ "alice2.txt" };

	//transform(어디부터, 어디까지, 어디로, 어떻게)
	transform(istreambuf_iterator<char>(inOld), istreambuf_iterator<char>(), ostreambuf_iterator<char>(out), [](char c)
		{
			if (!isalpha(c) && c != '\n')
				c = ' ';
			return c;
		});

	ifstream inNew{ "alice2.txt" };

	for (auto i = istream_iterator<string>(inNew); i != istream_iterator<string>(); ++i)
		words[*i]++;	// 연관배열: 변수[key] = value -> 해당 key의 value값을 1씩 더한다.

	for (const auto& i : words)
		isMap.emplace(i.second, i.first);
	for (const auto& i : isMap)
		cout << i.first << " " << i.second << endl;

	cout << "-----------------------------------------------------------------------------------------------------------" << endl;

	for (const auto& i : words)
		cout << i.first << " " << i.second << endl;

	cout << isMap.size() << endl;
	cout << words.size() << endl;
}


// alice2.txt에서 사용자가 입력한 단어가 몇 번 사용되었는가 출력하라
void solution4()
{
	string word{};
	map<string, int> words{};
	ifstream in{ "alice2.txt" };

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		words[*i]++;	// 연관배열: 변수[key] = value -> 해당 key의 value값을 1씩 더한다.

	while (1)
	{
		cout << "찾으실 단어는?: ";
		cin >> word;

		auto p = words.find(word);

		if (p != words.end())
			cout << word << "의 사용횟수: " << p->second << endl;
		else
			cout << "해당 단어 없음!" << endl;
	}
}


// alice2.txt에 사용된 단어를 오름차순으로 alice3.txt에 저장하자
void solution5()
{
	map<string, string> words{};
	ifstream in{ "alice2.txt" };
	ofstream out{ "alice3.txt" };

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		words.emplace(*i, *i);

	// 정렬된 파일에 기록
	for (const auto& i : words)
		out << i.first << endl;

	// a로 시작하는 단어는 몇개인가?

	// 비효율적인 방법
	/*int cnt{};
	for (const auto &i : words)
		if (i.first[0] == 'a')
			cnt++;*/

	// 효율적인 방법
	auto beginA = words.lower_bound("a");
	auto endA = words.lower_bound("b");

	cout << "a로 시작하는 단어의 개수: " << distance(beginA, endA) << endl;
}

int main()
{
	//solution1();
	//solution2();
	//solution3();
	//solution4();
	solution5();
}