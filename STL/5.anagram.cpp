//----------------------------------------------------------
//distance
//�а� �ڷ�ǿ��� �ܾ��.zip�� ����
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
	ifstream in{ "�ܾ��.txt" };
	auto p = max_element(istream_iterator<string>(in), istream_iterator<string>(), [](const string& a, const string& b)
		{
			return a.size() < b.size();
		});
	cout << "���� �� �ܾ�� " << *p << endl;
}

void readData()
{
	string s{};
	ifstream in{ "�ܾ��.txt" };
	while (in >> s)
		v.emplace_back(s);

	cout << "��� " << v.size() << "���� �ܾ���� ��������ϴ�." << endl;
}

int main()
{
	readData();

	//v�� first ���� ������������ �����Ѵ�.
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

		//[b,e)�� �ֳʱ׷��̴�.
		list<string> t{};
		for (auto i = b; i < e; ++i)
			t.emplace_back(i->second);

		vl.emplace_back(t);
		b = e;
	}

	//vl ���� ������ ����
	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b)
		{
			return a.size() > b.size();
		});

	ofstream out{ "������ ���� ������ ������ �ֳʱ׷�.txt" };

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
	cout << "Anagram�� ã�� �帳�ϴ�." << endl;
	cout << "------------------------" << endl;
	cout << endl;*/

	//�ܾ �Է¹޾� �ֳʱ׷��� ã�� ����
	//while (true)
	//{
	//	cout << "ã�� �ܾ�?";
	//	string s;
	//	cin >> s;
	//	SP sp{ s };

	//	auto r = equal_range(v.begin(), v.end(), sp, [](const SP& a, const SP& b) {
	//		return a.first < b.first;
	//	});
	//	int d = distance(r.first, r.second);
	//	if (d == 0) {
	//		cout << "������ ���� �ܾ��Դϴ�." << endl;
	//		continue;
	//	}
	//	if (d == 1) {
	//		cout << "������ ������ �ֳʱ׷��� ����" << endl;
	//		continue;
	//	}
	//	//��¥ �����ϴ� �ܾ����� ��������
	//	bool f = none_of(r.first, r.second, [&s](const SP& a) {
	//		return a.second == s;
	//	});
	//	if (f == true) {
	//		cout << "������ ���� �ܾ��̴�" << endl;
	//		continue;
	//	}

	//	cout << "�ֳʱ׷��� - ";
	//	for (auto i = r.first; i < r.second; ++i)
	//		cout << i->second << "  ";
	//	cout << endl;

	//	if (binary_search(v.begin(), v.end(), sp, [](const SP& a, const SP& b) {
	//		return a.first < b.first; })) {
	//		cout << "������ �ִ� �ܾ�" << endl;
	//		auto p = equal_range(v.begin(), v.end(), sp, [](const SP &a, const SP b) {
	//			return a.first < b.first;
	//		});
	//		int d = distance(p.first, p.second);
	//		if (d == 1)
	//			cout << "�ֳʱ׷��� ���� �ܾ�" << endl;
	//		else {
	//			//[first,second)
	//			for (auto i = p.first; i < p.second; ++i)
	//				cout << i->second << " ";
	//			cout << endl;
	//		}
	//	}
	//	else
	//		cout << "���� �ܾ�" << endl;
}