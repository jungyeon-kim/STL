#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// binary_search: "���ĵǾ� �ִ�" begin���� end�� Ư�� �����̳� ���� ������ ��� true�� ��ȯ (����Ž��)

// �⺻������ <�����ڸ� ����ϸ� ==������ ��� !(a < b) && !(b < a)�� ���� ������ ������ ���θ� �Ǵ��Ѵ�.

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	sort(v.begin(), v.end());
	bool p = binary_search(v.begin(), v.end(), 5);

	if (p)
		cout << "����" << endl;
	else
		cout << "�������" << endl;
}