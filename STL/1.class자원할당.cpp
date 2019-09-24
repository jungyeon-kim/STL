#include <iostream>
#include <random>
#include <string>

using namespace std;

// String은 자원을 할당하는 클래스이다.
// 1. 생성 시 new로 할당
// 2. 소멸시 delete로 해제
// 3. 복사생성자에서 깊은복사를 한다.
// 4. 대입연산자에서 깊은복사를 한다.

// char배열(문자열)은 초기화시 맨끝의버퍼 하나를 비워놔야한다. (그 이후에는 채워져도 상관없음)

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int num{};
	char *p{};
public:
	String(int n)	// 생성자
	{
		cout << "String()" << endl;
		num = n;
		p = new char[num];	// string 타입 num개 할당
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}
	~String()	// 소멸자
	{
		cout << "~String()" << endl;
		if (p)
		{
			delete[] p;
			p = nullptr;
		}
	}
	String(const String &rhs)	// 복사생성자
	{
		cout << "String(const String &rhs)" << endl;
		// 얕은복사			// 문제점	1. lhs의 메모리해제가 일어나면 rhs는 가리키는값이 사라짐 (댕글링포인터)
		// p = rhs.p;		//			2. 소멸자에서 메모리해제 두번일어남 (오류)
		// 깊은복사
		if (p) delete[] p;	// 할당된 값이있다면 해제(안해주면 주인없는 주소값이 돌아다님)
		num = rhs.num;					// p에 복사되는 배열크기를 복사
		p = new char[rhs.num];			// p에 복사되는 배열크기를 빈 공간에 할당
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];			// 값 복사
	}

	String& operator=(const String &rhs)	// 대입연산자
	{
		cout << "String& operator=(const String &rhs)" << endl;
		if (p) delete[] p;
		num = rhs.num;
		p = new char[rhs.num];
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];

		return *this;
	}
	friend ostream &operator<<(ostream &os, const String& rhs)	// 출력연산자
	{
		for (int i = 0; i < rhs.num; ++i)
			os << rhs.p[i] << " ";
		return os;
	}
};

int main()
{
	String a{ 20 };	// 생성자 호출
	String b = a;	// 복사생성자 호출
	String c{ 0 };	// 생성자 호출
	c = a;			// 대입연산자 호출

	cout << a << endl;	// 출력연산자 호출
	cout << b << endl;	// "
	cout << c << endl;	// "
}