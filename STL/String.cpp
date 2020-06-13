#include "String.h"
#include "Iter.h"
#include <memory>
#include <random>
#include <iterator>

using namespace std;

default_random_engine dre{};
uniform_int_distribution<> uid{ 'a', 'z' };

String::String(int n) : num{ n }
{
	p = make_unique<char[]>(num);
	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);

	cout << "String(int n): " << this << " HEAP:" << &p << endl;
}
String::~String()
{
	cout << "~String(): " << this << " HEAP: " << &p << endl;
}
String::String(const String& rhs)
{
	num = rhs.num;
	p = make_unique<char[]>(rhs.num);
	for (int i = 0; i < rhs.num; ++i)
		p[i] = rhs.p[i];

	cout << "String(const String &rhs): " << this << " ����: " << &rhs << " HEAP: " << &p << endl;
}
String::String(String&& rhs) noexcept
{
	num = rhs.num;			// �Ϲ��ڷ����� �̵��ø�ƽ�� ���� �ȵ��־ move�� �ǹ̾���
	p = std::move(rhs.p);	// unique_ptr�� ���簡 �Ұ����ϱ⿡ move�� �̿��� �̵��ø�ƽ�� ���

	cout << "String(String &&rhs): " << this << " ����: " << &rhs << " HEAP: " << &p << endl;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs) return *this;
	num = rhs.num;
	p = make_unique<char[]>(rhs.num);
	for (int i = 0; i < rhs.num; ++i)
		p[i] = rhs.p[i];

	cout << "String& operator=(const String&rhs)" << endl;

	return *this;
}
String& String::operator=(String&& rhs) noexcept
{
	if (this == &rhs) return *this;
	num = rhs.num;
	p = std::move(rhs.p);

	cout << "String& operator=(String &&rhs)" << endl;

	return *this;
}
ostream& operator<<(ostream& os, const String& rhs)
{
	for (int i = 0; i < rhs.num; ++i)
		os << rhs.p[i] << " ";
	return os;
}
bool String::operator==(const String& rhs) const
{
	return num == rhs.num;
}
bool String::operator<(const String& rhs) const
{
	return num < rhs.num;
}

int String::getNum() const { return num; }
char String::getP() const { return p[0]; }

Iter String::begin() { return Iter{ &p[0] }; }
Iter String::end() { return Iter{ &p[num] }; }
RevIter String::rbegin() { return RevIter{ &p[num] }; }
RevIter String::rend() { return RevIter{ &p[0] }; }