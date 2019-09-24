#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

// 전역 데이터는 실행 파일의 어디에 어떻게 기록되는가?
// int arr[100];
// int arr[100] = { 0 };
// 위 두 선언 방식의 차이점을 설명해보자

// 40000바이트가 필요하다?
// 파일을 default text mode 말고 binary mode 로 열어야 한다.
// binary mode: 컴퓨터 내의 2진법으로 기본적인 연산이 수행되는 경우의 연산

constexpr int MAX = 10000;

void readFile(string fname)
{
	int data = 0;
	ifstream in(fname, ios::binary);	// 파일읽기를 binary모드로 한다.

	for (int i = 0; i < MAX; ++i)
	{
		in.read((char*)(&data), sizeof(int));
		cout << data << endl;
	}
}

void writeFile(string fname)
{
	int* arr = new int[MAX];
	ofstream out(fname, ios::binary);			// 파일쓰기를 binary 모드로 한다.
	default_random_engine dre;					// 엔진
	uniform_int_distribution<> uid(0, 1000);	// 분포(~부터, ~까지)

	for (int i = 0; i < MAX; ++i)
		arr[i] = uid(dre);	// 분포(엔진)

	sort(&arr[0], &arr[MAX], [](int left, int right)	// sort(어디부터, 어디까지, 어떻게)
		{
			return left < right;
		});

	for (int i = 0; i < MAX; ++i)
		cout << arr[i] << " ";
	cout << endl;

	out.write((char*)arr, MAX * sizeof(int));	// (char형 주소값, 데이터양)

	delete[] arr;
}

int main()
{
	int command = 0;

	while (command != 3)
	{
		cout << "SAVE[1], ROAD[2], EXIT[3]: ";
		cin >> command;

		switch (command)
		{
		case 1:
			writeFile("binary_data.bin");
			break;
		case 2:
			readFile("binary_data.bin");
			break;
		}
	}
}