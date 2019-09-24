#pragma once
#include <iostream>

class Iter;
class RevIter;

class String
{
private:
	int num{};
	std::unique_ptr<char[]> p{};
public:
	String(int n);
	~String();
	String(const String& rhs);
	String(String&& rhs);

	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	friend std::ostream& operator<<(std::ostream& os, const String& rhs);
	bool operator==(const String& rhs) const;
	bool operator<(const String& rhs) const;

	int getNum() const;
	char getP() const;

	Iter begin();
	Iter end();
	RevIter rbegin();
	RevIter rend();
};