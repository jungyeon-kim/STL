#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "String.h"

using namespace std;

/*
	순차 컨테이너 "vector"
	사용처:	삽입, 삭제 성능보다 접근 성능이 중요한 경우
			배열을 사용하면서 크기가 동적으로 커지거나 줄어들 경우
*/

/*
	1.	연속된 메모리이기 때문에, array처럼 index에 즉시 접근이 가능해 O(1)로 접근 성능이 좋다.
	2.  인덱스 끝에 대한 삽입과 삭제는 평균 O(1)로 매우 빠르다. 
		하지만, 그외의 인덱스에서는 뒤에 있는 모든 인덱스들을 밀거나 당기는 작업을 해야해서 O(N-p)로 느리다.
	3.  값을 넣을 공간이 없으면 더 큰 공간(원래크기의 1.5배)을 재할당한다.
	4.  멤버함수 -> size, capacity, data (크기, 할당가능공간, 저장위치)
	5.	루프에서 삭제동작시, iterator때문에 주의가 필요하다. 이는 모든 컨테이너에 적용되는 사례이다.
		추가적으로 원시 포인터를 저장할 시, 메모리 해제작업도 해주어야한다. -> 따라서, 스마트포인터를 추천
*/

/*
	push_back():			인자로서 필요한 임시객체를 생성 후 복사 or 이동이 일어난다. (생성자, 복사생성자 호출)
	emplace_back():			인자로서 필요한 객체를 컨테이너에 바로 생성한다. (생성자 or 복사생성자 호출)
	reserve():				()개가 들어갈 공간을 잡아준다. -> ()개까지 공간재할당(복사생성자호출)을 막아준다.
	erase():				삭제동작 후, 다음 iterator를 반환한다. (루프안에서 삭제동작시 주의가 필요하다.)
	erase(remove(), end()):	vector는 remove()가 내장되지 않아 특정값을 지울 수 없어 이와 같이 사용한다.
							remove()가 해당 값들을 다음값으로 덮어씌운다. -> 의미없는 값들이 뒤에 생기고 
							그 영역의 시작을 가리키는 반복자 반환. 하지만, 의미없는 값들 때문에 size는 변함이 없다.
							따라서, erase()를 이용해 remove() 반환값부터 end()까지 데이터만 삭제 (capacity는 변함없음)
*/


// 비어있는 v에 String 20개를 추가하라
// String의 값을 uid(10, 70)으로 초기화
// String의 문자를 오름차순으로 정렬
// v를 String의 길이 오름차순으로 정렬
// 결과를 화면에 출력
void solution1()
{
	vector<String> v{};		// 아직 객체가 생성된 상태가 아님

	default_random_engine dre;
	uniform_int_distribution<> uid{ 10,	20 };

	for (int i = 0; i < 20; ++i)
		v.emplace_back(uid(dre));

	sort(v.begin(), v.end(), [](const String& left, const String& right)
		{
			return left.getP() < right.getP();
		});

	for (const auto& i : v)		// 순회방법 1 (추천)
		cout << i << endl;

	cout << endl;

	sort(v.begin(), v.end());	// 클래스 내부 <연산자 오버로딩 때문에 세번째 인자 불필요.

	for (auto i = v.cbegin(); i != v.cend(); ++i)	// 순회방법 2
		cout << *i << endl;	// 반복자는 포인터를 반환하기 떄문에 역참조로 값을 가져와야함.
}

// 입력자료 - 키보드
// 출력자료 - 화면
// 키보드에서 string을 입력받아 정렬 후 화면 출력하라.
void solution2()
{
	vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };	// (키보드 시작, 키보드 끝)

	sort(v.begin(), v.end());

	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
}

// 소스.cpp에서 e를 제거한 결과를 e없는소스.cpp에 저장하라
// remove_if로 e를 제거한다. (erase에는 if기능이 없다.)
// 공백까지 처리하기위해 istreambuf_iterator, ostreambuf_ierator를 사용
void solution3()
{
	ifstream in{ "소스.cpp" };
	ofstream out{ "e없는소스.cpp" };
	vector<char> v{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };

	auto p = remove_if(v.begin(), v.end(), [](const char& c)
		{
			return c == 'e';
		});
	v.erase(p, v.end());

	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));
}

// 벡터의 삭제동작시 주의사항에 대해서 알아보자.
// 인덱스 루프로 삭제하는 경우와 반복자 루프로 삭제하는 경우가 있다.
// 범위기반포문은 ++연산을 사용자가 컨트롤할 수 없으므로 사용하면 안된다.
void solution4()
{
	vector<int> v1{};
	vector<int> v2{};

	for (int i = 0; i < 10; ++i)
	{
		v1.emplace_back(i);
		v2.emplace_back(i);
	}

	//	index
	for (int i = 0; i < v1.size();)
	{
		if (v1[i] % 2 == 0) v1.erase(v1.begin() + i);	// v1.begin()은 갱신된다. 삭제된 iterator를 지울 일이 없다.
		else ++i;										// ++i는 index를 더한다.
	}													// 따라서, erase()의 반환되는 다음 iterator를 알필요가 없다.
	//	iterator
	for (auto i = v2.begin(); i < v2.end();)
	{
		if (*i % 2 == 0) i = v2.erase(i);				// i에 대입안하면, 삭제된 iterator를 또 지우려한다. (에러)
		else ++i;										// ++i는 iterator를 더한다.
	}													// 따라서, erase()의 반환되는 다음 iterator를 알아야한다.

	for (const auto& i : v1) cout << i << " ";
	cout << endl;
	for (const auto& i : v2) cout << i << " ";
}

// 벡터의 이해를 돕기위한 함수.
void testVector()
{
	vector<String> v{};

	//v.reserve(1000);

	while (1)
	{
		cout << "벡터의 원소 갯수		-> " << v.size() << endl;
		cout << "담을 수 있는 원소의 갯수	-> " << v.capacity() << endl;
		cout << "원소가 저장되어있는 위치	-> " << v.data() << endl;

		char c{};
		cin >> c;

		v.emplace_back(10);
	}
}

int main()
{
	testVector();
	//solution1();
	//solution2();
	//solution3();
	//solution4();
}