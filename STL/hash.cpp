/*
	해시 테이블 (hash table)

	해시 테이블을 구현할 때에는 버킷(bucket)이라는 배열에 대한 배열을 만들어 항목을 저장한다.
	각 버킷은 고유한 인덱스 번호를 가지고 해시함수는 key를 bucket의 인덱스 번호로 매핑한다.
	key와 쌍을 이루는 value는 매핑된 bucket에 저장된다.

	키(key):					고유한 값이며, 해시 함수의 input이 된다. 다양한 길이의 값이 될 수 있다.
							이 상태로 최종 저장소에 저장이 되면 다양한 길이 만큼의 저장소를 구성해 두어야 하기 때문에
							해시 함수로 값을 바꾸어 저장이 되어야 공간의 효율성을 추구할 수 있다.
	해시함수(Hash Function): 키(key)를 해시(hash)로 바꿔주는 역할을 한다. 다양한 길이를 가지고 있는 키(key)를
							일정한 길이를 가지는 해시(hash)로 변경하여 저장소를 효율적으로 운영할 수 있도록 도와준다.
							다만, 서로 다른 키(key)가 같은 해시(hash)가 되는 경우를 해시 충돌(hash collision)이라고
							하는데, 해시 충돌을 일으키는 확률을 최대한 줄이는 함수를 만드는 것이 중요하다.
	해시(Hash):				해시 함수(hash function)의 결과물이며,
							저장소(bucket, slot)에서 값(value)과 매칭되어 저장된다.
	값(Value):				저장소(bucket, slot)에 최종적으로 저장되는 값으로 키와 매칭되어
							저장, 삭제, 검색, 탐색이 가능해야 한다.

	장점)
	1.	삽입, 삭제, 탐색 성능이 O(1)을 지향한다. (해시충돌이 없는 완벽한 해시일 경우에 해당)

	단점)
	1.	순서와 무관하게 동작하기 때문에, 순서가 중요한 데이터에 사용하는 것은 바람직하지 못하다.
	2.	미리 메모리를 잡아두기 때문에, 메모리가 부족하거나 남을 수 있어 공간복잡도가 비효율적이다. (동적해싱으로 해결)
	3.	성능의 시간복잡도는 해시 함수를 포함하지 않는다. 따라서, 해시함수가 복잡하게 구현될수록 성능이 저하된다.

	해시 충돌을 피하는 방법)
	1.	체이닝 (chaining):
		bucket에 hash값이 충돌하면 list 구조를 이용하여 해당 hash값에 매칭되는 value에 다른 value를 연결시킨다.
			장점:	1.	제한된 메모리(bucket)를 효율적으로 사용할 수 있다.
					2.	해시함수 구현의 중요도가 상대적으로 적어진다.
					3.	상대적으로 적은 메모리를 사용한다.
			단점:	1.	한 hash값에 value가 집중적으로 연결될수록 효율성이 떨어진다.
					2.	list 구조에 대한 처리로 인해 추가적인 비용이 발생한다.
	2.	개방주소법 (open addressing):
		hash값이 변경되지 않았던 chaining 기법과 달리 hash값이 충돌하면 비어있는 hash값을 찾아 value를 저장한다.
		이로써 하나의 hash에는 하나의 value만 존재하게된다.
			장점:	1.	list 구조를 도입하지않아도 내부적으로 해시충돌을 피할 수 있다.
						따라서, 외부저장공간에 대한 추가적인 비용이 발생하지 않는다.
			단점:	1.	해시함수 구현의 중요도가 상대적으로 많아진다.
					2.	빈 공간을 이용하기 때문에, 상대적으로 많은 메모리를 사용한다.


	출처: https://velog.io/@cyranocoding/Hash-Hashing-Hash-Table%ED%95%B4%EC%8B%9C-%ED%95%B4%EC%8B%B1-%ED%95%B4%EC%8B%9C%ED%85%8C%EC%9D%B4%EB%B8%94-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%EC%9D%98-%EC%9D%B4%ED%95%B4-6ijyonph6o
*/