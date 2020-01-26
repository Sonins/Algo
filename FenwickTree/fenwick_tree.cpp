#include <iostream>

#define MAX 100000

typedef long long ll;

ll tr[MAX];
ll diff[MAX]; // 구간 업데이트를 위해서 필요한 트리

/**
 *************  Fenwick Tree     *************
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
 *************  트리 업데이트    *************
 * 초기화 & 업데이트 구현 원리는
 * index' = index + index & (-index)로 Tr[index']를 반복 참조 했을 때,
 * Tr[index'] 가 Tr[index]를 포함하는 노드 인 것을 이용한다.
 * 
 * 예를 들어, index가 5 일때,
 * index    = 5;
 * index'   = index + (index & -index) = 5 + 1 = 6
 * index''  = index' + (index' & -index') = 6 + 2 = 8
 * index가 5 -> 6 -> 8의 순서로 Arr[index = 5] 를 포함하는 트리의 노드만 순회한다.
 * 따라서 펜윅 트리의 초기화 비용은 O(NlogN)과 같다.
 * 
 *************       구간 합     *************
 * 펜윅 트리를 이용해서 구간 합을 구하는 방법은
 * index' = index - index & (index)로 Tr[index']를 반복 참조 했을 때,
 * index'(n)이 1 ~ index 의 대푯값을 모두 참조 할 수 있는 점을 이용한다.
 * 
 * 예를 들어, index가 13 일때,
 * index    = 13;
 * index'   = index - (index & index) = 13 - 1 = 12
 * index''  = 12 - 4 = 8
 * 이 때
 * Tr[index]    = Tr[13] = Arr[13]
 * Tr[index']   = Tr[12] = Arr[12] + ... + Arr[12 - 4 + 1] = Sum[Arr[12 ~ 9]]
 * Tr[index'']  = Tr[8]  = Arr[8] + ... + Arr[8 - 8 + 1] = Sum[Arr[8 ~ 1]]
 * 그러므로 Tr[index] + Tr[index'] + Tr[index'']은 Sum[Arr[1 ~ 13]]이 된다.
 * 
 * 구간 합인 Sum[Arr[L ~ R]]의 경우 Sum[Arr[1 ~ R]] - Sum[Arr[1 ~ L]] 이므로
 * 펜윅 트리를 이용해서 구간합 Sum[Arr[L ~ R]]을 구할 수 있게 된다.
 * 
 * 이 비용은 O(logN)이다.
*/

/**
 * 트리 초기화
 * index' = index + index & -index 임을 이용한다. 
*/

void init_tree(ll arr[], int size) {
    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        index = (int) i;
        while (index > MAX)
        {
            tr[index] += arr[i];
            index += index & (-index);
        }
        
    }
    return;
}

/**
 * 구간 합 구하기
 * tree_sum(index) 이라는 함수로 Tr[1] ... Tr[index] 까지의 합을 구하고
 * tree_range_sum(L, R) 이라는 함수로 tree_sum(R) - tree_sum(L)을 반환하게 함으로써
 * 결과적으로 Tr[L] ... Tr[R] 까지의 합을 반환하게 한다.
*/

ll tree_sum(int index) {
    ll result = 0;
    while (index > 0) {
        result += tr[index];
        index -= index & (-index);
    }
    return result;
}

ll tree_range_sum (int L, int R) {
    return tree_sum(R) - tree_sum(L);
}

/**
 * 구간 업데이트
 * (구간 합을 구한다는 가정 하에)
 * diff 라는 펜윅 트리를 하나 더 만들고
 * diff 에 구간 합을 저장한다.
 * 
 * 이 때, 저장하는 방법은 다음과 같은 원리를 이용한다.
 * 
 * 
*/

