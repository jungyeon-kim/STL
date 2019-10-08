#include <iostream>
#include <queue>

using namespace std;

/*
	컨테이너 어댑터 "queue"
	사용처:	FIFO 구조가 필요할 경우
*/

/*
	1.	FIFO(선입선출)로 동작한다.
	2.	삽입, 삭제에 효율적이다.
	3.	defalut 템플릿 파라미터로 deque을 사용한다.
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