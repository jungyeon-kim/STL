#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

/*
	���� �����̳� "map"
	���ó:	key�� value�� ���� �̷�� ����, ����, Ž���� ���� �� ������ �ʿ��� ���
*/

/*
	1.	����, ����, Ž�� ������ ��� O(logN)�̴�.
		����, ����:	vector���� ������, list���� ������.
		Ž��:		vector���� ������, list���� ������.
	2.	dictionary���� -> key�� value�� �� ���� �̷�� �ߺ��� �Ұ��ϴ�. (multimap�� ����)
		�㳪, multimap�� �ߺ��Ǵ� key���� ������ �� �ֱ⶧���� []�����ڸ� �������� �ʴ´�.
	3.	�׸��� ����� ��, key�� �������� ������ ������. (default�� less���� ������������ ���ĵȴ�. ���������� greater)
	4.	�Ϲ� find()�� �ƴ� map�� ����� find()�� ����Ѵ�. (����Ž�� �˰���) -> O(log n)
	5.	�迭�� �ε���(key ��)�� �ܼ��� int���� �ƴ� string���� ������ Ÿ���� ����� �� �ִ�.
*/

/*
	insert():		��ü�� ������ �����̳ʿ� �����Ű�Ƿ� key, value�� ������ ������ ��üȭ(make_pair)�� ���Ѿ� �Ѵ�.
	emplace():		�����̳� ��ü�� ��ü�� �����ϹǷ� �׷���(make_pair)�� �ʿ����.
	equal_range():	�����Լ��� �����Ѵ�. (lower_bound()�� upper_bound() ���� �����Ѵ�.)
	first:			key����� ���ٰ���
	second:			value����� ���ٰ���
	pair<T, U>:		�� �����Ͱ� �� ���� �̷�� ���� -> make_pair()�� �� ������ ����
					���������� first�� second�� �����Ѵ�.
*/


// �׷��̸��� �Է��Ͽ� map�� ������ ��� key, value�� ����϶�
// map�� �������� ������� �����迭�� �̿��� �����϶�
void solution1()
{
	map<string, int> idols{};

	idols.insert(pair<string, int>("����", 5));
	idols.insert(make_pair("��ź�ҳ��", 7));
	idols.emplace("�������", 12);
	idols.emplace("���ʿ�", 11);

	while (1)
	{
		string name{};

		cout << "���̵� ��: ";
		cin >> name;

		auto p = idols.find(name);

		if (p != idols.end())
			cout << p->first << " " << p->second << endl;
		else
		{
			int num{};

			cout << "�������. �ο��� �Է�: ";
			cin >> num;

			idols[name] = num;	// key�� name�� value�� num���� �����Ѵ�.
		}
	}
}


// �ҽ�.cpp�� ���� ���ĺ��� ���Ƚ���� ����϶�
void solution2()
{
	map<char, int> words{};
	ifstream in{ "�ҽ�.cpp" };

	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
		words[*i]++;	// �����迭: ����[key] = value -> �ش� key�� value���� 1�� ���Ѵ�.

	for (const auto& i : words)
		cout << i.first << " " << i.second << endl;
}


// alice.txt�� ���� �ܾ ���Ƚ���� ������������ ����϶�
// ���ĺ��� �ƴ� ���ڴ� �������� ó��

void solution3()
{
	map<string, int> words{};
	multimap<int, string> isMap{};
	ifstream inOld{ "alice.txt" };
	ofstream out{ "alice2.txt" };

	//transform(������, ������, ����, ���)
	transform(istreambuf_iterator<char>(inOld), istreambuf_iterator<char>(), ostreambuf_iterator<char>(out), [](char c)
		{
			if (!isalpha(c) && c != '\n')
				c = ' ';
			return c;
		});

	ifstream inNew{ "alice2.txt" };

	for (auto i = istream_iterator<string>(inNew); i != istream_iterator<string>(); ++i)
		words[*i]++;	// �����迭: ����[key] = value -> �ش� key�� value���� 1�� ���Ѵ�.

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


// alice2.txt���� ����ڰ� �Է��� �ܾ �� �� ���Ǿ��°� ����϶�
void solution4()
{
	string word{};
	map<string, int> words{};
	ifstream in{ "alice2.txt" };

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		words[*i]++;	// �����迭: ����[key] = value -> �ش� key�� value���� 1�� ���Ѵ�.

	while (1)
	{
		cout << "ã���� �ܾ��?: ";
		cin >> word;

		auto p = words.find(word);

		if (p != words.end())
			cout << word << "�� ���Ƚ��: " << p->second << endl;
		else
			cout << "�ش� �ܾ� ����!" << endl;
	}
}


// alice2.txt�� ���� �ܾ ������������ alice3.txt�� ��������
void solution5()
{
	map<string, string> words{};
	ifstream in{ "alice2.txt" };
	ofstream out{ "alice3.txt" };

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		words.emplace(*i, *i);

	// ���ĵ� ���Ͽ� ���
	for (const auto& i : words)
		out << i.first << endl;

	// a�� �����ϴ� �ܾ�� ��ΰ�?

	// ��ȿ������ ���
	/*int cnt{};
	for (const auto &i : words)
		if (i.first[0] == 'a')
			cnt++;*/

	// ȿ������ ���
	auto beginA = words.lower_bound("a");
	auto endA = words.lower_bound("b");

	cout << "a�� �����ϴ� �ܾ��� ����: " << distance(beginA, endA) << endl;
}

int main()
{
	//solution1();
	//solution2();
	//solution3();
	//solution4();
	solution5();
}