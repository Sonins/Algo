#include <iostream>
#include <vector>
using namespace std;
int main() {
    int comb = 1;
    long long arr[11] = {
        100,
        2147483600,
        298855,
        123456789,
        2147483636,
        20000255,
        1234512033,
        1578774571,
        200073,
        1357924680,
        1578574497
    };
    long long sum = 328;
    vector<int> wrong;
    int SCORE;
    cin >> SCORE;
    while (comb < (1 << 11)) {

        for (size_t i = 0; i < 11; i++) {
            if (comb & (1 << i))
                sum = (sum + arr[i]) % 2147483648;
            else
            {
                wrong.push_back(i);
            }
            
        }

        if (sum == SCORE) {
            for (auto i : wrong)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
        }

        wrong.clear();
        sum = 328;
        comb++;
    }
    return 0;
}
/**
 * 서브태스크 1 (100점)
수열의 모든 수가 양수이다. 즉, 모든 1 ≤ i ≤ n에 대해 ai > 0이다.
서브태스크 2 (2147483600점)
수열의 모든 수가 음수이다. 즉, 모든 1 ≤ i ≤ n에 대해 ai < 0이다.
서브태스크 3 (298855점)
양의 정수 x에 대해 f(x) = (x의 각 자리 숫자의 세제곱의 합)이라 하고, f1(x) = f(x), fk(x) = f(fk-1(x)) (k > 1)라 하자. fk(n) = 1인 양의 정수 k가 존재한다.
서브태스크 4 (123456789점)
입력으로 주어진 수열의 가장 긴 증가하는 부분 수열의 길이가 318의 배수이다. (부분 수열은 연속하지 않아도 된다.)
서브태스크 5 (2147483636점)
이 서브태스크의 데이터는 예제 하나뿐이다. 아니, 예제도 안 돌려보고 코드를 제출하는 사람이 있나요?
서브태스크 6 (20000255점)
이 서브태스크의 데이터도 역시 하나인데, 출제자가 직접 손으로 타이핑하여 만들었다.
이 서브태스크의 데이터는 다른 서브태스크의 데이터에 들어 있지 않다.
서브태스크 7 (1234512033점)
이 서브태스크에서 n ≥ 6이며, 이 서브태스크의 모든 데이터는 다음과 같은 과정을 통해 생성되었다.

a1, a2, a3, a4, a5는 -999,999,999 이상 999,999,999 이하의 수 중에서 임의로 결정된다.
k ≥ 6일 때, Sk는 a1, a2, ... , ak-1 중 5개를 첨자(index)의 중복 없이 뽑아서 곱한 값들을 모두 더한 값이다. 예를 들어, S7 = a1a2a3a4a5 + a1a2a3a4a6 + a1a2a3a5a6 + a1a2a4a5a6 + a1a3a4a5a6 + a2a3a4a5a6이다. -999,999,999 이상 999,999,999 이하의 수 중에서 1,999,999,999로 나눈 나머지가 Sk와 같은 수를 ak로 정한다.
서브태스크 8 (1578774571점)
입력으로 주어진 수열의 가장 긴 감소하지 않는 부분 수열의 길이를 p, 가장 긴 증가하지 않는 부분 수열의 길이를 q라고 할 때, pq ≥ n이다. (부분 수열은 연속하지 않아도 된다.)
서브태스크 9 (200073점)
이 서브태스크에는 데이터가 없다.
서브태스크 10 (1357924680점)
(a1 + a2x + a3x2 + ... + anxn-1)2 = (b0 + b1x + b2x2 + b3x3 + ... + b2n-2x2n-2)라 할 때, bi들 중 홀수가 짝수보다 많다.
서브태스크 11 (1578574497점)
이 서브태스크에 한하여 "제한" 부분에 있는 ai 제한이 적용되지 않는다. 즉, ai의 절댓값은 1,000,000,000보다 클 수 있다. ai는 여전히 정수이며, 정규 표현식으로 (-?[1-9][0-9]*|0)의 형태로 주어진다.
입력으로 들어오는 두 번째 줄의 길이(문자의 개수)는 3,600,000 이상 10,000,000 이하이다.
*/