#pragma once
#include <iostream>

class Iter : public std::iterator<std::random_access_iterator_tag, char>
{
private:
	iterator::pointer p{};
public:
	Iter(iterator::pointer p);

	iterator::difference_type operator-(const Iter& rhs) const;
	Iter operator+(iterator::difference_type rhs) const;
	Iter operator-(iterator::difference_type rhs) const;

	bool operator<(const Iter& rhs) const;
	bool operator>(const Iter& rhs) const;
	bool operator!=(const Iter& rhs) const;
	bool operator==(const Iter& rhs) const;

	iterator::value_type operator*() const;
	iterator::reference operator*();
	Iter& operator++();			// pre-increment
	Iter operator++(int);		// post-increment
	Iter& operator--();
	Iter operator--(int);
};

class RevIter
{
private:
	char* p{};
public:
	RevIter(char* p);

	RevIter& operator++();		// pre-increment
	RevIter operator++(int);	// post-increment
	char& operator*();
	char operator*() const;
	bool operator!=(const RevIter& rhs) const;
};