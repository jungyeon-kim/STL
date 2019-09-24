#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>
#include <random>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ---------------------------------------------------------------------------------------------
// ���ĵ������� ���������̳� "unorderedMap"
// 	- dictionary���� -> key�� value�� �� ���� �̷�
//	- find(): �ð����⵵: O(1) -> map���� ������. but, �޸𸮸� ���
// ---------------------------------------------------------------------------------------------

class Dog
{
private:
	string name{};

public:
	Dog(string name) : name{ name } {}

	const bool& operator==(const Dog& rhs) const
	{
		return name == rhs.name;
	}

	const string& getName() const
	{
		return name;
	}
};

struct DogHash
{
	size_t operator()(const Dog& rhs) const
	{
		return hash<string>{}(rhs.getName());
	}
};

// �ʰ� �������ʿ� �������� 1000������ ��´�.
// find�Լ��� ȣ���Ͽ� ã�µ� �ɸ��� �ð��� ���.
constexpr int MAX{ 1000000 };

void solution1()
{
	uniform_int_distribution<> intUid{};
	default_random_engine intDre{};
	int i{};
	// map ��������
	map<int, int> m{};
	while (m.size() != MAX * 10)
		m.emplace(intUid(intDre), ++i);
	// unorderedMap ��������
	unordered_map<int, int> um{ m.begin(), m.end(), 1000000 };
	// vector ��������
	vector<int> v{};
	v.reserve(MAX);
	for (int i = 0; i < MAX; ++i)
		v.emplace_back(intUid(intDre));

	// find
	{
		auto begin = chrono::steady_clock::now();
		cout << "map�� find �ӵ�: ";
		for (int i = 0; i < MAX; ++i)
			m.find(v[i]);
		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		auto begin = chrono::steady_clock::now();
		cout << "unorderedMap�� find �ӵ�: ";
		for (int i = 0; i < MAX; ++i)
			um.find(v[i]);
		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
}

// unorderedMap�� ���ظ� �������� �Լ�
void testUnorderedMap()
{
	unordered_map<Dog, int, DogHash> um{};

	um.emplace("����", 10);
	um.emplace("����", 7);
	um.emplace("����", 3);

	for (int i = 0; i < um.bucket_count(); ++i)
	{
		cout << "[" << i << "]";
		if (um.bucket_size(i))
		{
			cout << " - ";
			for (auto p = um.begin(i); p != um.end(i); ++p)
				cout << p->second << " ";
		}
		cout << endl;
	}
}

int main()
{
	//testUnorderedMap();
	solution1();
}