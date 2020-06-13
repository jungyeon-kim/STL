#include <iostream>
#include <queue>

using namespace std;

/*
	�����̳� ����� "priority_queue"
	���ó:	�켱������ �ִ� FIFO ������ �ʿ��� ���
*/

/*
	1.	queue�� �����ϳ� �켱������ �ο��� �� �ִ�. (�׸��� pop�� ��, �켱������ ����ȴ�.)
		�켱������ ���� ���, queue�� �����ϰ� FIFO ��Ģ�� ������.
	2.	�׸��� �׻� ���ĵ� ���·� �����Ѵ�. 
		����, ����, ������ �Ͼ ������ �켱������ ���߾� �������ϹǷ� queue���� �ӵ��� ������.
	3.	defalut ���ø� �Ķ���ͷ� vector�� ����Ѵ�.
	4.	default�� less������, �⺻������ ū���� �켱������ ���� ū���� �տ������� ���ĵȴ�.
*/

/*
	top():	stack�� �ٸ��� top�� �Ǿտ� �����Ѵ�. (�켱������ ���ĵǱ� ����)
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