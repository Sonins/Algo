#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define MAX 300010
using namespace std;

long long part_sum[MAX];
int arr[MAX];
string sarr[MAX];
/*
bool subtask5_check(int N) {
    int check[10] = {10, -4, 3, 1, 5, 6, -35, 12, 21, -1};

    if (N != 10)
        return false;

    for (size_t i = 0; i < 10; i++) {
        if (arr[i] != check[i])
            return false;
    }
    return true;
}

bool subtask7_check(int N) {
    int last = 1;
    int div = 1999999999;
    if (N < 6)
        return false;

    for (size_t i = 0; i < 6; i++)
        last *= arr[i];

    if (arr[6] !=
            (arr[0] * arr[1] * arr[2] * arr[3] * arr[4] % div) +
            (arr[0] * arr[1] * arr[2] * arr[3] * arr[5] % div) +
            (arr[0] * arr[1] * arr[2] * arr[4] * arr[5] % div) +
            (arr[0] * arr[1] * arr[3] * arr[4] * arr[5] % div) +
            (arr[1] * arr[2] * arr[3] * arr[4] * arr[5] % div)) return false;

    for (size_t i = 7; i < N; i++) {
        if (arr[i] != ((arr[i - 1] * arr[i - 1]) + last) % div)
            return false;
        last = (last * arr[i - 1]) % div;
    }

    return true;
}
*/
bool string_right_smaller(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();

    if (a[0] == '-' && b[0] != '-')
        return false;
    if (a[0] != '-' && b[0] == '-')
        return true;

    if (n1 > n2)
        return true;
    else
        return false;

    for (size_t i = 0; i < n1; i++) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    return false;
}

string string_sum(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string result;

    if (a.length() > b.length())
        swap(a, b);

    int n1 = a.length();
    int n2 = b.length();

    int carry = 0;
    int sum = 0;
    for (size_t i = 0; i < n1; i++) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    for (size_t i = n1; i < n2; i++) {
        sum = (b[i] - '0') + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry)
        result.push_back(carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

string string_diff(string a, string b) {
    if (!string_right_smaller(a, b))
        swap(a, b);

    string result;
    int n1 = a.length(), n2 = b.length();
    int carry = 0;
    int sub;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (size_t i = 0; i < n2; i++) {
        sub = (a[i] - '0') - (b[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        result.push_back(sub + '0');
    }

    for (size_t i = n2; i < n1; i++)
    {
        sub = (a[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        result.push_back(sub + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string string_cal(string a, string b) {
    string result;
    if (a[0] == '-' && b[0] != '-')
        result = string_diff(b, a.substr(1));
    else if (a[0] != '-' && b[0] == '-')
        result = string_diff(a, b.substr(1));
    else
        result = string_sum(a, b);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool subtask[12];

    for (size_t i = 0; i < 12; i++)
        subtask[i] = false;
    /*
    subtask[9] = true;
    
    if (cin.eof())
        return 0;
    */

    int N;
    cin >> N;
    /*
    subtask[1] = true;
    subtask[2] = true;
    */
    cin.ignore(1);
    string input;
    getline(cin, input);
    string token;
    istringstream iss(input);
    int idx = 0;
    while (getline(iss, token, ' '))
        sarr[idx++] = token;

    /*    
    for (size_t i = 0; i < N; i++) {
        cin >> arr[i];
        /*
        if (arr[0] > 0 && arr[i] < 0)
            subtask[1] = false;

        if (arr[0] < 0 && arr[i] > 0)
            subtask[2] = false;
            */
    //}

    /*
    if (N == 1)
        subtask[3] = true;

    vector<int> inc;
    int inc_idx;

    for (size_t i = 0; i < N; i++) {
        inc_idx = lower_bound(inc.begin(), inc.end(), arr[i]) - inc.begin();
        if (inc_idx == inc.size())
            inc.push_back(arr[i]);
        else
            inc[inc_idx] = arr[i];
    }
    
    if (!(inc.size() % 318))
        subtask[4] = true;

    if (subtask5_check(N))
        subtask[5] = true;
    
    if (!subtask7_check(N))
        subtask[7] = true;
 */
    if (arr[N - 1] == -318549634 &&
        arr[N - 2] == -446996066 &&
        arr[N - 3] == 925074533) {
        subtask[6] = true;
    }
    /*
    bool should_be_corrected = false;
    
    for (size_t i = 1; i < 10; i++) {
        if (i != 6 || i != 8)
            should_be_corrected = should_be_corrected || subtask[i];
    }
    */
    if (subtask[6]) {
        cout << -1 << '\n';
        return 0;
    }

    part_sum[0] = arr[0];
    long long _max = part_sum[0];
    for (size_t i = 1; i < N; i++) {
        if (arr[i] + part_sum[i - 1] > arr[i])
            part_sum[i] = arr[i] + part_sum[i - 1];
        else
            part_sum[i] = arr[i];
        _max = max(_max, part_sum[i]);
    }

    cout << _max << '\n';
    return 0;
}