#include <iostream>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

// ---------------------------------------------------------------------------------------------
// ���������̳� "set"
// 	- key�� ���� (key�� �ߺ��Ұ�)
//	- multiset: �ߺ��Ǵ� key���� �������ִ�.
//	- map�� ���������� �����Լ��� find()�� �����Ѵ�.
//	- ������ ������ ������ �������� ȿ�����̴�.
//	- ���Ƿ� ���� ���� ������ �� ����. -> ��� Ÿ���� �׻� const�̴�.
//	- default�� less���� ������������ ���ĵȴ�. (���������� greater)
// ---------------------------------------------------------------------------------------------


// "alice2.txt"�� multiset���� �о�´�.
// �ܾ��� ���Ƚ���� ������������ ȭ�鿡 ����϶�
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