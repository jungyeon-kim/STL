#include <iostream>
#include <random>
#include <string>

using namespace std;

// String�� �ڿ��� �Ҵ��ϴ� Ŭ�����̴�.
// 1. ���� �� new�� �Ҵ�
// 2. �Ҹ�� delete�� ����
// 3. ��������ڿ��� �������縦 �Ѵ�.
// 4. ���Կ����ڿ��� �������縦 �Ѵ�.

// char�迭(���ڿ�)�� �ʱ�ȭ�� �ǳ��ǹ��� �ϳ��� ��������Ѵ�. (�� ���Ŀ��� ä������ �������)

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int num{};
	char *p{};
public:
	String(int n)	// ������
	{
		cout << "String()" << endl;
		num = n;
		p = new char[num];	// string Ÿ�� num�� �Ҵ�
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}
	~String()	// �Ҹ���
	{
		cout << "~String()" << endl;
		if (p)
		{
			delete[] p;
			p = nullptr;
		}
	}
	String(const String &rhs)	// ���������
	{
		cout << "String(const String &rhs)" << endl;
		// ��������			// ������	1. lhs�� �޸������� �Ͼ�� rhs�� ����Ű�°��� ����� (��۸�������)
		// p = rhs.p;		//			2. �Ҹ��ڿ��� �޸����� �ι��Ͼ (����)
		// ��������
		if (p) delete[] p;	// �Ҵ�� �����ִٸ� ����(�����ָ� ���ξ��� �ּҰ��� ���ƴٴ�)
		num = rhs.num;					// p�� ����Ǵ� �迭ũ�⸦ ����
		p = new char[rhs.num];			// p�� ����Ǵ� �迭ũ�⸦ �� ������ �Ҵ�
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];			// �� ����
	}

	String& operator=(const String &rhs)	// ���Կ�����
	{
		cout << "String& operator=(const String &rhs)" << endl;
		if (p) delete[] p;
		num = rhs.num;
		p = new char[rhs.num];
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];

		return *this;
	}
	friend ostream &operator<<(ostream &os, const String& rhs)	// ��¿�����
	{
		for (int i = 0; i < rhs.num; ++i)
			os << rhs.p[i] << " ";
		return os;
	}
};

int main()
{
	String a{ 20 };	// ������ ȣ��
	String b = a;	// ��������� ȣ��
	String c{ 0 };	// ������ ȣ��
	c = a;			// ���Կ����� ȣ��

	cout << a << endl;	// ��¿����� ȣ��
	cout << b << endl;	// "
	cout << c << endl;	// "
}