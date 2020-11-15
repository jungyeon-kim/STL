#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	 "정렬된 상태에서" -> logn
	 distance:		begin이 end까지 도달하는데에 증가된 횟수를 반환
	 lower_bound:	begin에서 end중 조건에 만족하는 값의 첫 iterator를 반환 (없으면 다음 값)
	 upper_bound:	begin에서 end중 조건에 만족하는 값의 마지막 다음 iterator를 반환 (없으면 다음 값)
	 equal_range:	begin에서 end중 조건에 만족하는 lower_bound와 upper_bound의 iterator 쌍을 반환
					pair 구조이기 때문에 first와 second로 lb와 ub에 접근가능
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