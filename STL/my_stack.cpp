#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	T* arr{};
	int topIdx{ -1 };
	int maxSize{ 1 };
private:
	void deepCopy(const Stack& rhs)
	{
		arr = new T[rhs.maxSize];
		for (int i = 0; i < rhs.maxSize; ++i) arr[i] = rhs.arr[i];
		topIdx = rhs.topIdx;
		maxSize = rhs.maxSize;
	}
	void resize()
	{
		T* newArr{ new T[maxSize *= 2] };
		copy(arr, arr + maxSize / 2, newArr);
		delete[] arr;
		arr = newArr;
	}
public:
	Stack() { arr = new T[maxSize]; };
	Stack(const Stack& rhs) { deepCopy(rhs); cout << "บนป็" << endl; }
	~Stack() { if (arr) { delete[] arr; arr = nullptr; } }

	Stack& operator=(const Stack& rhs) { if (arr) delete[] arr; deepCopy(rhs); return *this; }

	void push(const T& value) { if (topIdx == maxSize - 1) resize(); arr[++topIdx] = value; }
	void pop() { if (!empty()) --topIdx; }
	int size() const { return topIdx + 1; }
	int capacity() const { return maxSize; }
	bool empty() const { return topIdx == -1 ? true : false; }
	void reverse() { for (int i = 0; i < size() / 2; ++i) swap(arr[i], arr[size() - i - 1]); }
	T& top() const { static T tmp{}; return empty() ? tmp : arr[topIdx]; }
};

int main()
{
	Stack<int> stk{};
	string command{};
	int value{};

	while (true)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> value;
			stk.push(value);
		}
		else if (command == "pop")
			stk.pop();

		cout << "---------------------" << endl;
		cout << "empty: " << stk.empty() << endl;
		cout << "front: " << stk.top() << endl;
		cout << "size: " << stk.size() << endl;
		cout << "capacity: " << stk.capacity() << endl;
		cout << "---------------------" << endl;
	}
}