#include <iostream>
#include <queue>

using namespace std;

/*
	컨테이너 어댑터 "priority_queue"
	사용처:	우선순위가 있는 FIFO 구조가 필요할 경우
*/

/*
	1.	queue와 동일하나 우선순위를 부여할 수 있다. (항목이 pop될 때, 우선순위가 고려된다.)
		우선순위가 같을 경우, queue와 동일하게 FIFO 원칙을 따른다.
	2.	항목을 항상 정렬된 상태로 유지한다. 
		따라서, 삽입, 삭제가 일어날 때마다 우선순위에 맞추어 재정렬하므로 queue보다 속도가 느리다.
	3.	defalut 템플릿 파라미터로 vector를 사용한다.
	4.	default가 less이지만, 기본적으로 큰값이 우선순위가 높아 큰값이 앞에오도록 정렬된다.
*/

/*
	top():	stack과 다르게 top이 맨앞에 존재한다. (우선순위로 정렬되기 때문)
*/

int main()
{
	priority_queue<int> q{};
	constexpr int QUEUE_SIZE{ 10 };

	for (int i = 0; i < QUEUE_SIZE; ++i)
		q.emplace(i);
	
	for (int i = 0; i < QUEUE_SIZE; ++i)
	{
		cout << "top: " << q.top() << endl;
		cout << "pop()" << endl;
		q.pop();
		cout << "empty: " << q.empty() << endl;
		cout << "---------------------" << endl;
	}
}