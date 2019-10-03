#include <iostream>

using namespace std;

class Dog
{
public:
	int operator()(int param)	// ()������ �����ε�
	{
		cout << "int operator()(int param)" << endl;
		return param * param;
	}
};

void func() { cout << "void func()" << endl; }

int main()
{
	// ȣ�Ⱑ��Ÿ�� ����

	// 1. �Ϲ��Լ�
	auto f1 = func;		// auto f1 = void(*f1)(void)
	f1();
	cout << "�Ϲ��Լ�: " << typeid(f1).name() << endl;

	// 2. ����
	auto f2 = []() {cout << "lambda[]()" << endl; };
	f2();
	cout << "�����Լ�: " << typeid(f2).name() << endl;

	// 3. �Լ���ü: ()�����ڸ� overloading�� Ŭ������ ��ü
	Dog dog;
	auto f3 = dog;
	f3(3);
	cout << "�Լ���ü: " << typeid(f3).name() << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <thread>
#include <chrono>

void durationTime()	// �귯�� �ð��� ��� �Լ�
{
	using namespace std::chrono;
	auto begin = chrono::steady_clock::now();	// ���۽ð��� begin�� ����
	this_thread::sleep_for(5000ms);				// ~��ŭ sleep ��Ų��.	(�̰��� ������� �־��ָ� ��)
	cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;	// ������ ���ð��� ���۽ð��� ���̸� ��� -> �����ϴµ� �ɸ��� �ð�
}