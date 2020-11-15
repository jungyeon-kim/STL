#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	 "���ĵ� ���¿���" -> logn
	 distance:		begin�� end���� �����ϴµ��� ������ Ƚ���� ��ȯ
	 lower_bound:	begin���� end�� ���ǿ� �����ϴ� ���� ù iterator�� ��ȯ (������ ���� ��)
	 upper_bound:	begin���� end�� ���ǿ� �����ϴ� ���� ������ ���� iterator�� ��ȯ (������ ���� ��)
	 equal_range:	begin���� end�� ���ǿ� �����ϴ� lower_bound�� upper_bound�� iterator ���� ��ȯ
					pair �����̱� ������ first�� second�� lb�� ub�� ���ٰ���
*/

template <typename Iter>
typename Iter::difference_type myDistance(Iter begin, Iter end, random_access_iterator_tag)
{
	return end - begin;
}
template <typename Iter>
typename Iter::difference_type myDistance(Iter begin, Iter end, input_iterator_tag)
{
	typename Iter::difference_type cnt{};
	while (begin++ != end) ++cnt;

	return cnt;
}
template <typename Iter>
typename Iter::difference_type myDistance(Iter begin, Iter end)
{
	return myDistance(begin, end, Iter::iterator_category());
}

int main()
{
	vector<int> v{ 1, 3, 3, 3, 4, 5, 6, 7, 8 };

	random_shuffle(v.begin(), v.end());
	sort(v.begin(), v.end());
	auto lb = lower_bound(v.begin(), v.end(), 3);
	auto ub = upper_bound(v.begin(), v.end(), 3);
	auto er = equal_range(v.begin(), v.end(), 3);

	cout << myDistance(lb, ub) << endl;
	cout << myDistance(er.first, er.second) << endl;
}