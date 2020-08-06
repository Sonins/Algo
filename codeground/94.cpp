/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <cmath>
#include <iostream>
#define PI 3.1415926536
using namespace std;

double Answer;

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

    // freopen("input.txt", "r", stdin);

    cin >> T;
    double obs[1010][3];  // l r h
    double R, S, E, N;
    cout.precision(16);
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        cin >> R >> S >> E;
        cin >> N;
        for (size_t i = 0; i < N; i++)
            cin >> obs[i][0] >> obs[i][1] >> obs[i][2];

        Answer += E - S;
        for (size_t i = 0; i < N; i++) {
            if (obs[i][2] < R) {
                Answer -= 2 * sqrt(R * R - (R - obs[i][2]) * (R - obs[i][2]));
                Answer += (PI - 2 * asin((R - obs[i][2]) / R)) * R;
            } else {
                Answer -= 2 * R;
                Answer += 2 * (obs[i][2] - R);
                Answer += PI * R;
            }
        }
        cout << "Case #" << test_case + 1 << '\n';
        cout << Answer << '\n';
    }

    return 0;  //Your program should return 0 on normal termination.
}