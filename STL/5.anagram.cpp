//----------------------------------------------------------
//distance
//학과 자료실에서 단어들.zip을 받자
//
//
//----------------------------------------------------------
#include<iostream>
#include"String.h"
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<list>
#include <iterator>

using namespace std;

struct SP : public pair<string, string>
{
	SP(string s) : pair(s, s)
	{
		sort(first.begin(), first.end());
	}
};

vector<SP> v{};

void firstFindWord()
{
	ifstream in{ "단어들.txt" };
	auto p = max_element(istream_iterator<string>(in), istream_iterator<string>(), [](const string& a, const string& b)
		{
			return a.size() < b.size();
		});
	cout << "가장 긴 단어는 " << *p << endl;
}

void readData()
{
	string s{};
	ifstream in{ "단어들.txt" };
	while (in >> s)
		v.emplace_back(s);

	cout << "모두 " << v.size() << "개의 단어쌍을 만들었습니다." << endl;
}

int main()
{
	readData();

	//v를 first 기준 오름차순으로 정렬한다.
	sort(v.begin(), v.end(), [](const SP& a, const SP& b)
		{
			return a.first < b.first;
		});

	vector<list<string>>vl{};

	vl.reserve(31000);

	auto b = v.begin();

	while (1)
	{
		b = adjacent_find(b, v.end(), [](const SP& a, const SP& b)
			{
				return a.first == b.first;
			});

		if (b == v.end())
			break;

		auto e = find_if_not(b + 1, v.end(), [b](const SP& a)
			{
				return a.first == b->first;
			});

		//[b,e)는 애너그램이다.
		list<string> t{};
		for (auto i = b; i < e; ++i)
			t.emplace_back(i->second);

		vl.emplace_back(t);
		b = e;
	}

	//vl 갯수 순으로 정렬
	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b)
		{
			return a.size() > b.size();
		});

	ofstream out{ "갯수가 많은 순서로 정렬한 애너그램.txt" };

	for (const list<string>& l : vl)
	{
		out << "[" << l.size() << "]";
		for (const string& s : l)
		{
			out << s << " ";
		}
		out << endl;
	}

	/*cout << "------------------------" << endl;
	cout << "Anagram을 찾아 드립니다." << endl;
	cout << "------------------------" << endl;
	cout << endl;*/

	//단어를 입력받아 애너그램을 찾아 주자
	//while (true)
	//{
	//	cout << "찾을 단어?";
	//	string s;
	//	cin >> s;
	//	SP sp{ s };

	//	auto r = equal_range(v.begin(), v.end(), sp, [](const SP& a, const SP& b) {
	//		return a.first < b.first;
	//	});
	//	int d = distance(r.first, r.second);
	//	if (d == 0) {
	//		cout << "사전에 없는 단어입니다." << endl;
	//		continue;
	//	}
	//	if (d == 1) {
	//		cout << "사전에 있지만 애너그램은 없다" << endl;
	//		continue;
	//	}
	//	//진짜 존재하는 단어인지 골라봐야함
	//	bool f = none_of(r.first, r.second, [&s](const SP& a) {
	//		return a.second == s;
	//	});
	//	if (f == true) {
	//		cout << "사전에 없는 단어이다" << endl;
	//		continue;
	//	}

	//	cout << "애너그램들 - ";
	//	for (auto i = r.first; i < r.second; ++i)
	//		cout << i->second << "  ";
	//	cout << endl;

	//	if (binary_search(v.begin(), v.end(), sp, [](const SP& a, const SP& b) {
	//		return a.first < b.first; })) {
	//		cout << "사전에 있는 단어" << endl;
	//		auto p = equal_range(v.begin(), v.end(), sp, [](const SP &a, const SP b) {
	//			return a.first < b.first;
	//		});
	//		int d = distance(p.first, p.second);
	//		if (d == 1)
	//			cout << "애너그램이 없는 단어" << endl;
	//		else {
	//			//[first,second)
	//			for (auto i = p.first; i < p.second; ++i)
	//				cout << i->second << " ";
	//			cout << endl;
	//		}
	//	}
	//	else
	//		cout << "없는 단어" << endl;
}