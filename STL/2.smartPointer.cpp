#include <iostream>
#include <random>
#include <string>
#include <memory>

using namespace std;

/*
	unique_ptr: �ڿ��� ���� (�� ����!) -> ���簡 �Ұ��� (�̵��ø�ƽ���� ����)
	shared_ptr: �ڿ��� ����

	reset():	���� �޸𸮸� �����ϰ� �ٸ� �޸𸮸� �Ҵ��Ѵ�. (���ڰ� ������ ������ ����)
	release():	�޸𸮴� �����ϵ� �ڿ��� �������� ���ְ� �����͸� ��ȯ�Ѵ�. (unique_ptr���� ����)
				release()�� ��ȯ�� �����ʹ� �ݵ�� ����ڰ� delete ���־�� �Ѵ�.
*/

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int num{};
	unique_ptr<char[]> p{};	// unique_ptr<�ڷ���> ������
public:
	String(int n)	// ������
	{
		cout << "String()" << endl;
		num = n;
		p = make_unique<char[]>(num);	// string Ÿ�� num�� �Ҵ�
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}
	~String()	// �Ҹ���
	{
		cout << "~String()" << endl;
	}
	String(const String& rhs)	// ���������
	{
		cout << "String(const String& rhs)" << endl;
		// ��������			// ������	1. lhs�� �޸������� �Ͼ�� rhs�� ����Ű�°��� ����� (��۸�������)
		// p = rhs.p;		//			2. �Ҹ��ڿ��� �޸����� �ι��Ͼ (����)
		// ��������
		num = rhs.num;					// p�� ����Ǵ� �迭ũ�⸦ ����
		p = make_unique<char[]>(rhs.num);			// p�� ����Ǵ� �迭ũ�⸦ �� ������ �Ҵ�
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];			// �� ����
	}

	String& operator=(const String& rhs)	// ���Կ�����
	{
		cout << "String& operator=(const String& rhs)" << endl;
		num = rhs.num;
		p = make_unique<char[]>(rhs.num);
		for (int i = 0; i < rhs.num; ++i)
			p[i] = rhs.p[i];

		return *this;
	}
	friend ostream &operator<<(ostream& os, const String& rhs)	// ��¿�����
	{
		for (int i = 0; i < rhs.num; ++i)
			os << rhs.p[i] << " ";
		return os;
	}
};

int main()
{
	String a{ 20 };	// ������ ȣ��
	String b{ a };	// ��������� ȣ��
	String c{ 0 };	// ������ ȣ��
	c = a;			// ���Կ����� ȣ��

	cout << a << endl;	// ��¿����� ȣ��
	cout << b << endl;	// "
	cout << c << endl;	// "
}