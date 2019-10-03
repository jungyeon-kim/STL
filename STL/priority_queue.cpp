#include <iostream>

using namespace std;

/*
	컨테이너 어댑터 "priority_queue"
	사용처:	우선순위가 있는 FIFO 구조가 필요할 경우
*/

/*
	1. queue와 동일하나 우선순위를 부여할 수 있다. (항목이 pop될 때, 우선순위가 고려된다.)
	2. 우선순위가 같을 경우, queue와 동일하게 FIFO 원칙을 따른다.
	3. 삽입, 삭제가 일어날 때마다 우선순위에 맞추어 재정렬하므로 queue보다 속도가 느리다.
*/