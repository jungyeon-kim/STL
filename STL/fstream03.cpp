#include <iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std;

constexpr int MAX = 1000;

default_random_engine dre;
uniform_int_distribution<> uid(0, 20);
uniform_int_distribution<> uidName('a', 'z');

class Dog
{
private:
	char name[11];	// 이름은 임의의 소문자 10글자로 구성
	int age;		// 0 ~ 20 사이의 값
public:
	Dog()
	{
		for (int i = 0; i < 10; ++i)
			name[i] = uidName(dre);
		name[10] = NULL;
		age = uid(dre);
	}

	friend ostream& operator<<(ostream& os, const Dog& rhs)
	{
		os << "이름: " << rhs.name << " 나이: " << rhs.age;
		return os;
	}

	inline string getName() const { return (string)name; }
};

void writeFile(string fname)
{
	Dog dog[MAX];

	sort(begin(dog), end(dog), [](const Dog& left, const Dog& right)
		{
			return left.getName() < right.getName();
		});

	ofstream out(fname, ios::binary);
	out.write((char*)dog, sizeof(Dog) * MAX);
}

void readFile(string fname)
{
	Dog dog;
	ifstream in(fname, ios::binary);

	for (int i = 0; i < MAX; ++i)
	{
		in.read((char*)& dog, sizeof(Dog));
		cout << dog << endl;
	}
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