#include <iostream>
#include <random>
#include <string>
#include <memory>

using namespace std;

/*
	unique_ptr: 자원을 독점 (꼭 쓰자!) -> 복사가 불가능 (이동시맨틱으로 가능)
	shared_ptr: 자원을 공유

	reset():	현재 메모리를 해제하고 다른 메모리를 할당한다. (인자가 없을시 해제만 동작)
	release():	메모리는 유지하되 자원의 소유권을 없애고 포인터를 반환한다. (unique_ptr에만 존재)
				release()로 반환한 포인터는 반드시 사용자가 delete 해주어야 한다.
*/

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int num{};
	unique_ptr<char[]> p{};	// unique_ptr<자료형> 변수명
public:
	String(int n)	// 생성자
	{
		cout << "String()" << endl;
		num = n;
		p = make_unique<char[]>(num);	// string 타입 num개 할당
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}
	~String()	// 소멸자
	{
		cout << "~String()" << endl;
	}
	String(const String& rhs)	// 복사생성자
	{
		cout << "String(const String& rhs)" << endl;
		// 얕은복사			// 문제점	1. lhs의 메모리해제가 일어나면 rhs는 가리키는값이 사라짐 (댕글링포인터)
		// p = rhs.p;		//			2. 소멸자에서 메모리해제 두번일어남 (오류)
		// 깊은복사
		num = rhs.num;					// p에 복사되는 배열크기를 복사
		p = make_unique<char[]>(rhs.num);			// p에 복사되는 배열크기를 빈 공간에 할당
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];			// 값 복사
	}

	String& operator=(const String& rhs)	// 대입연산자
	{
		cout << "String& operator=(const String& rhs)" << endl;
		num = rhs.num;
		p = make_unique<char[]>(rhs.num);
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];

		return *this;
	}
	friend ostream &operator<<(ostream& os, const String& rhs)	// 출력연산자
	{
		for (int i = 0; i < rhs.num; ++i)
			os << rhs.p[i] << " ";
		return os;
	}
};

int main()
{
	String a{ 20 };	// 생성자 호출
	String b{ a };	// 복사생성자 호출
	String c{ 0 };	// 생성자 호출
	c = a;			// 대입연산자 호출

	cout << a << endl;	// 출력연산자 호출
	cout << b << endl;	// "
	cout << c << endl;	// "
}