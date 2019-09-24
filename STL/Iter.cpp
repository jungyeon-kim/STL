#include "Iter.h"
#include <iterator>

using namespace std;

Iter::Iter(iterator::pointer p) : p{ p } {}

Iter::iterator::difference_type Iter::operator-(const Iter& rhs) const
{
	return p - rhs.p;
}
Iter Iter::operator+(iterator::difference_type rhs) const
{
	return Iter{ p + rhs };
}
Iter Iter::operator-(iterator::difference_type rhs) const
{
	return Iter{ p - rhs };
}

bool Iter::operator<(const Iter& rhs) const
{
	return p < rhs.p;
}
bool Iter::operator>(const Iter& rhs) const
{
	return p > rhs.p;
}
bool Iter::operator!=(const Iter& rhs) const
{
	return p != rhs.p;
}
bool Iter::operator==(const Iter& rhs) const
{
	return p == rhs.p;
}

Iter::iterator::value_type Iter::operator*() const
{
	return *p;
}
Iter::iterator::reference Iter::operator*()
{
	return *p;
}
Iter& Iter::operator++()		// pre-increment
{
	++p;
	return *this;
}
Iter Iter::operator++(int)		// post-increment
{
	Iter tmp{ *this };	// 쓸데없는 객체를 만든다.
	++(*this);
	return tmp;
}
Iter& Iter::operator--()
{
	--p;
	return *this;
}
Iter Iter::operator--(int)
{
	Iter tmp{ *this };
	--(*this);
	return tmp;
}

RevIter::RevIter(char* p) : p{ p } {}

RevIter& RevIter::operator++()		// pre-increment
{
	--p;
	return *this;
}
RevIter RevIter::operator++(int)		// post-increment
{
	RevIter tmp{ *this };	// 쓸데없는 객체를 만든다.
	++(*this);
	return tmp;
}
char& RevIter::operator*()			// 쓰기모드
{
	return *(p - 1);
}
char RevIter::operator*() const		// 읽기모드
{
	return *(p - 1);
}
bool RevIter::operator!=(const RevIter& rhs) const
{
	return p != rhs.p;
}