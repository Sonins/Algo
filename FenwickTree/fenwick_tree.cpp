#include <iostream>

#define MAX 100000


int tr[MAX];

/**
 * Fenwick Tree
 * 빠른 업데이트 & 구간 쿼리를 위한 자료 구조.
 * 
 * 기본 개념은 Tr[i] = func(Arr[i], Arr[i - 1], ... , Arr[i - (i & -i) + 1])이다.
 * 이를 시각화하면 아래와 같다.
 * 
 *         1        2        3        4        5        6        7        8        9        10       : Arr Index
 * <----Tr[1]        <----Tr[3]        <----Tr[5]        <----Tr[7]        <----Tr[9]                
 * <-------------Tr[2]                 <-------------Tr[6]                 <-------------Tr[10]
 * <-------------------------------Tr[4]
 * <-------------------------------------------------------------------Tr[8]                         : Tr Value 
 * 
 * 트리 업데이트
 * 초기화 & 업데이트 구현 원리는
 * index' += index & (-index)로 Tr[index']를 반복 참조 했을 때,
 * Tr[index'] 가 Tr[index]를 포함하는 노드 인 것을 이용한다.
 * 
 * 예를 들어, index가 5 일때,
 * index    = 5;
 * index'   = index + (index & -index) = 5 + 1 = 6
 * index''  = index' + (index' & -index') = 6 + 2 = 8
 * index가 5 -> 6 -> 8의 순서로 Arr[index = 5] 를 포함하는 트리의 노드만 순회한다.
 * 따라서 펜윅 트리의 초기화 비용은 O(NlogN)과 같다.
*/