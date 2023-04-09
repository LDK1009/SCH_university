set create() // 빈 집합을 생성하는 함수
set insert(set s, Nat_Number x) // 원소 x를 집합 s에 추가하는 함수
set remove(set s, Nat_Number x) // 원소 x를 집합 s에서 제거하는 함수
bool is_in(set s, Nat_Number x) // 원소 x가 집합 s에 포함되어 있는지 확인하는 함수
set union(set s1, set s2) // 두 집합 s1과 s2를 합쳐서 새로운 집합을 만드는 함수
set intersection(set s1, set s2) // 두 집합 s1과 s2의 교집합을 구하는 함수
set difference(set s1, set s2) // 두 집합 s1과 s2의 차집합을 구하는 함수
