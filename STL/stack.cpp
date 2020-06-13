#include <iostream>
#include <stack>

using namespace std;

/*
	컨테이너 어댑터 "stack"
	사용처:	FILO 또는 LIFO 구조가 필요할 경우
*/

/*
	1.	FILO(선입후출) 또는 LIFO(후입선출)로 동작한다.
	2.	삽입, 삭제에 효율적이다.
	3.	defalut 템플릿 파라미터로 deque을 사용한다.
*/

int main()
{
	stack<int> stk{};
}