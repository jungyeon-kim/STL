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

/*
	비정렬 연관 컨테이너 "unordered_map" -> 동적 해시테이블
	사용처:	정렬될 필요가 없고,
			key와 value가 쌍을 이루고 삽입, 삭제, 탐색에 대한 고른 성능이 필요할 경우
*/

/*
	1.	삭입, 삭제, 탐색 성능이 평균적으로 O(1)이다.
	2.	정렬되지 않는다는 것을 제외하고는 map과 같다.
*/

/*
	find():			시간복잡도: O(1) -> map보다 빠르다. but, 메모리를 희생
	size():			들어있는 원소의 개수
	bucket_size():	버켓의 개수
*/

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

// 맵과 언오더드맵에 랜덤정수 1000만개를 담는다.
// find함수를 호출하여 찾는데 걸리는 시간을 잰다.
constexpr int MAX{ 10000 };

void solution1()
{
	uniform_int_distribution<> intUid{};
	default_random_engine intDre{};
	int i{};
	// map 정수생성
	map<int, int> m{};
	while (m.size() != MAX * 10)
		m.emplace(intUid(intDre), ++i);
	// unorderedMap 정수생성
	unordered_map<int, int> um{ m.begin(), m.end(), 10000 };
	// vector 정수생성
	vector<int> v{};
	v.reserve(MAX);
	for (int i = 0; i < MAX; ++i)
		v.emplace_back(intUid(intDre));

	// find
	{
		auto begin = chrono::steady_clock::now();
		cout << "map의 find 속도: ";
		for (int i = 0; i < MAX; ++i)
			m.find(v[i]);
		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
	{
		auto begin = chrono::steady_clock::now();
		cout << "unorderedMap의 find 속도: ";
		for (int i = 0; i < MAX; ++i)
			um.find(v[i]);
		cout << duration_cast<milliseconds>(chrono::steady_clock::now() - begin).count() << endl;
	}
}

// unorderedMap의 이해를 돕기위한 함수
void testUnorderedMap()
{
	unordered_map<Dog, int, DogHash> um{};

	um.emplace("별이", 10);
	um.emplace("콩이", 7);
	um.emplace("해피", 3);

	cout << um.bucket_count() << endl;

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
	unordered_map<int, int> um{};

	for (int i = 0; i < 65; ++i)
		um.emplace(i, i);

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
	//testUnorderedMap();
	//solution1();
}