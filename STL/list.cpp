#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include "String.h"

using namespace std;

/*
	순차 컨테이너 "list"
	사용처:	접근 성능보다 삽입, 삭제 성능이 중요한 경우
*/

/*
	1.	포인터만 바꾸면 되어서 어떤 위치에서든 삽입삭제 동작이 O(1)로 매우빠르다.
	2.	원소에 접근하려면 처음이나 끝부터 선형탐색을 해야해서 O(N)으로 느리다.
	3.	순방향으로만 순회해도 된다면 단방향 연결리스트인 "forward_list"를 사용한다.
	4.	원소 하나보다 더 큰 메모리가 필요하다
	5.	연속된 메모리가 아니다.
*/

/*
	remove():	vector와 다르게 내장함수로 존재한다. (remove 후 erase 해주지 않아도 됨)
	merge():	list를 합친다. -> 정렬된 list에만 사용가능하다.
	unique():	중복되는 값을 지운다.
	splice():	원하는 구간을 빼온다.
*/


// 두 리스트를 merge하여 중복되는 값을 제외하고 출력하라.
void solution1()
{
	list<String> lst1{ 3, 6, 7, 3, 2, 1, 5 };
	list<String> lst2{ 2, 4, 6, 8, 10 };

	lst1.sort();
	lst2.sort();
	lst1.merge(lst2);
	lst1.unique();

	cout << "-------------------------------------------" << endl;
	for (const String& i : lst1)
		cout << i << endl;
	cout << "-------------------------------------------" << endl;
	for (const String& i : lst2)
		cout << i << endl;
	cout << "-------------------------------------------" << endl;
}

// "소스.cpp" 파일을 읽어라
// 길이순으로 정렬하라 -> 여기까진 벡터를 써도되지만
// 길이가 4인 단어를 따로 빼서 "길이4.txt"에 저장하라 -> 중간삭제때문에 리스트를 써야함

void solution2()
{
	ifstream in{ "소스.cpp" };
	ofstream out{ "길이4.txt" };
	list<string> lst{ istream_iterator<string>(in), istream_iterator<string>() };

	lst.sort([](const string& lhs, const string& rhs)
		{
			return lhs.length() < rhs.length();
		});

	// 길이가 4인 위치, 5인 위치를 찾는다.
	auto pos4 = find_if(lst.begin(), lst.end(), [](const string& rhs)	// begin부터 end까지 순회하다 길이가 4인 문자열을 만나면 값을 리턴한다.
		{
			return rhs.length() == 4;
		});
	auto pos5 = find_if(lst.begin(), lst.end(), [](const string& rhs)
		{
			return rhs.length() == 5;
		});

	// 이제 옮겨보자
	list<string> lst4{};
	lst4.splice(lst4.begin(), lst, pos4, pos5);	// 어디에, 무엇을, 어디부터, 어디까지
	copy(lst4.begin(), lst4.end(), ostream_iterator<string>(out, "\n"));	// out파일에 한칸씩 띄면서 저장
	copy(lst.begin(), lst.end(), ostream_iterator<string>(cout, "\n"));
}

int main()
{
	solution1();
	//solution2();
}