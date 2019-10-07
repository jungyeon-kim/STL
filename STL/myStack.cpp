#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	int topIdx{};
	static constexpr int MAX_SIZE{ 5000 };
	unique_ptr<T[]> p{};
public:
	Stack() : topIdx{ -1 } { p = make_unique<T[]>(MAX_SIZE); }
	~Stack() = default;
	
	void push(T num) { p[++topIdx] = num; }
	int pop()
	{
		if (empty()) return -1;
		p[topIdx--] = NULL;
	}
	int size() const { return topIdx + 1; }
	int empty() const { return topIdx == -1 ? 1 : 0; }
	T top() const { return empty() ? -1 : p[topIdx]; }
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
		cout << "top: " << stk.top() << endl;
		cout << "size: " << stk.size() << endl;
		cout << "---------------------" << endl;
	}
}