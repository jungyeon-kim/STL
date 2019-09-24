#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

// ���� �����ʹ� ���� ������ ��� ��� ��ϵǴ°�?
// int arr[100];
// int arr[100] = { 0 };
// �� �� ���� ����� �������� �����غ���

// 40000����Ʈ�� �ʿ��ϴ�?
// ������ default text mode ���� binary mode �� ����� �Ѵ�.
// binary mode: ��ǻ�� ���� 2�������� �⺻���� ������ ����Ǵ� ����� ����

constexpr int MAX = 10000;

void readFile(string fname)
{
	int data = 0;
	ifstream in(fname, ios::binary);	// �����б⸦ binary���� �Ѵ�.

	for (int i = 0; i < MAX; ++i)
	{
		in.read((char*)(&data), sizeof(int));
		cout << data << endl;
	}
}

void writeFile(string fname)
{
	int* arr = new int[MAX];
	ofstream out(fname, ios::binary);			// ���Ͼ��⸦ binary ���� �Ѵ�.
	default_random_engine dre;					// ����
	uniform_int_distribution<> uid(0, 1000);	// ����(~����, ~����)

	for (int i = 0; i < MAX; ++i)
		arr[i] = uid(dre);	// ����(����)

	sort(&arr[0], &arr[MAX], [](int left, int right)	// sort(������, ������, ���)
		{
			return left < right;
		});

	for (int i = 0; i < MAX; ++i)
		cout << arr[i] << " ";
	cout << endl;

	out.write((char*)arr, MAX * sizeof(int));	// (char�� �ּҰ�, �����;�)

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