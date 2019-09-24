#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
#include "String.h"

using namespace std;

// ǥ�� iterator�� ��ӹ޾� ���� iterator class�� ����
class MyIter : public iterator<bidirectional_iterator_tag, int>
{
private:
public:
};

template <typename T>
void print(T lhs, T rhs)
{
	for (auto p = lhs; p != rhs; ++p)
		cout << *p << endl;
}

template <typename T>
T add(T lhs, T rhs)
{
	cout << boolalpha << is_arithmetic<T>() << endl;

	return lhs + rhs;
}

template <typename T>
void f(T param)
{
	cout << typeid(iterator_traits<T>::iterator_category).name() << endl;		// ���ڷ� ���޵� �ݺ����� ���� ���
	cout << typeid(iterator_traits<T>::value_type).name() << endl;				// ���ڷ� ���޵� �ڷ����� ���� ���
}

int main()
{
	f(vector<int>::iterator());
	f(list<int>::iterator());
	f(forward_list<int>::iterator());
	f(ostream_iterator<int>(cout));
	f(istream_iterator<int>());
	f(MyIter());
}