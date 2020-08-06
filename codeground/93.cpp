/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#define MAX 1000010

using namespace std;

int Answer;
int dp[MAX];
int main(int argc, char** argv) {
    int T, test_case;

    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

    //freopen("sample_input.txt", "r", stdin);

    dp[2] = 1;

    for (int i = 4; i < MAX; i *= 2)
        dp[i] = dp[i / 2] + 1;

    for (int i = 3; i < MAX; i += 2) {
        dp[i] = dp[i + 1] + 1;
        for (int j = i * 2; j < MAX; j *= 2)
            dp[j] = dp[j / 2] + 1;
    }
    /*
    for (int i = 2; i < MAX; i++)
        dp[i] += dp[i - 1];
    */
    cin >> T;
    int N1, N2;
    for (test_case = 0; test_case < T; test_case++) {
        scanf("%d %d", &N1, &N2);
        Answer = dp[N2] - dp[N1 - 1];

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << '\n';
        cout << Answer << '\n';
    }

    return 0;  //Your program should return 0 on normal termination.
}