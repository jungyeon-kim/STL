#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue
{
private:
	T* arr{};
	int frontIdx{}, rearIdx{ -1 };
	int curSize{}, maxSize{ 1 };
private:
	void resize()
	{
		T* newArr{ new T[maxSize * 2] };

		if (frontIdx - rearIdx > 0)
		{
			copy(arr + frontIdx, arr + maxSize, newArr);
			copy(arr, arr + frontIdx, newArr + (maxSize - frontIdx));
			frontIdx = 0;
			rearIdx = maxSize - 1;
		}
		else copy(arr, arr + maxSize, newArr);

		delete[] arr;
		arr = newArr;
		maxSize *= 2;
	}
public:
	Queue() { arr = new T[maxSize]; }
	Queue(const Queue& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		frontIdx = rhs.frontIdx;
		rearIdx = rhs.rearIdx;
		curSize = rhs.curSize;
		maxSize = rhs.maxSize;
	}
	~Queue() { if (arr) { delete[] arr; arr = nullptr; } }

	void push(T value) { if (curSize == maxSize) resize(); arr[++rearIdx %= maxSize] = value; ++curSize; }
	void pop() { if (!empty()) { ++frontIdx %= maxSize; --curSize; } }
	int size() const { return curSize; }
	int capacity() const { return maxSize; }
	bool empty() const { return !curSize ? true : false; }
	T front() const { return empty() ? T{} : arr[frontIdx]; }
};

int main()
{
	Queue<int> que{};
	string command{};
	int value{};

	while (true)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> value;
			que.push(value);
		}
		else if (command == "pop")
			que.pop();

		cout << "---------------------" << endl;
		cout << "empty: " << que.empty() << endl;
		cout << "front: " << que.front() << endl;
		cout << "size: " << que.size() << endl;
		cout << "capacity: " << que.capacity() << endl;
		cout << "---------------------" << endl;
	}
}