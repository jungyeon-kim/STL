#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// count:		begin���� end���� Ư�� ���� ������ ��ȯ
// count_if:	begin���� end���� Ư�� ������ �����ϴ� ���� ������ ��ȯ

// ���׸� �Լ�: ���ø��� ���� Ÿ�����κ��� �����ο��� �Լ�
template <typename Iter, typename Pred>
size_t myCount_if(Iter begin, Iter end, Pred ty)
{
	int cnt{};

	while (begin != end)
		if (ty(*begin++))
			++cnt;
	// begin++; �� ���ǹ����� ���������ڷ� ++�� ���ְ� ����. ���� ���ʿ�
	return cnt;
}

class X
{
public:
	bool operator()(int n) const
	{
		return (n % 2) == 1;
	}
};

int main()
{
	vector<int> v{};

	v.reserve(100);
	for (int i = 0; i < 100; ++i)
		v.emplace_back(i + 1);

	auto n = myCount_if(v.begin(), v.end(), [](int n)	// ���� ���
		{
			return (n % 2) == 1;
		});
	// auto n = myCount_if(v.begin(), v.end(), X());	// �Լ���ü ���

	cout << "Ȧ���� ����: " << n << endl;
}