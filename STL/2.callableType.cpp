#include <iostream>

using namespace std;

class Dog
{
public:
	int operator()(int param)	// ()연산자 오버로딩
	{
		cout << "int operator()(int param)" << endl;
		return param * param;
	}
};

void func() { cout << "void func()" << endl; }

int main()
{
	// 호출가능타입 정리

	// 1. 일반함수
	auto f1 = func;		// auto f1 = void(*f1)(void)
	f1();
	cout << "일반함수: " << typeid(f1).name() << endl;

	// 2. 람다
	auto f2 = []() {cout << "lambda[]()" << endl; };
	f2();
	cout << "람다함수: " << typeid(f2).name() << endl;

	// 3. 함수객체: ()연산자를 overloading한 클래스의 객체
	Dog dog;
	auto f3 = dog;
	f3(3);
	cout << "함수객체: " << typeid(f3).name() << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <thread>
#include <chrono>

void durationTime()	// 흘러간 시간을 재는 함수
{
	using namespace std::chrono;
	auto begin = chrono::steady_clock::now();	// 시작시간을 begin에 저장
	this_thread::sleep_for(5000ms);				// ~만큼 sleep 시킨다.	(이곳에 연산들을 넣어주면 됨)
	cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;	// 연산의 끝시간과 시작시간의 차이를 출력 -> 연산하는데 걸리는 시간
}