#include <iostream>
#include <queue>

using namespace std;

/*
	�����̳� ����� "queue"
	���ó:	FIFO ������ �ʿ��� ���
*/

/*
	1.	FIFO(���Լ���)�� �����Ѵ�.
	2.	����, ������ ȿ�����̴�.
	3.	defalut ���ø� �Ķ���ͷ� deque�� ����Ѵ�.
*/

int main()
{
	queue<int> q{};
	constexpr int QUEUE_SIZE{ 10 };
	
	for (int i = 0; i < QUEUE_SIZE; ++i)
		q.emplace(i);

	for (int i = 0; i < QUEUE_SIZE; ++i)
	{
		cout << "front: " << q.front() << " back: " << q.back() << endl;
		cout << "pop()" << endl;
		q.pop();
		cout << "empty: " << q.empty() << endl;
		cout << "---------------------" << endl;
	}
}