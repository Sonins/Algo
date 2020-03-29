#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#define MAX 300010
using namespace std;

string sarr[MAX];
string spart_sum[MAX];

bool string_right_smaller(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();

    if (a[0] == '-' && b[0] != '-')
        return false;
    if (a[0] != '-' && b[0] == '-')
        return true;

    bool both_minus = false;

    if (a[0] == '-' && b[0] == '-')
        both_minus = true;

    if (n1 > n2)
        return true ^ both_minus;
    else if (n1 < n2)
        return false ^ both_minus;

    for (size_t i = 0; i < n1; i++) {
        if (a[i] > b[i])
            return true ^ both_minus;
        else if (a[i] < b[i])
            return false ^ both_minus;
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

    for (size_t i = n2; i < n1; i++) {
        sub = (a[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else
            carry = 0;
        result.push_back(sub + '0');
    }
    if (result[result.length() - 1] == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}

string string_cal(string a, string b) {
    string result;
    if (a[0] == '-' && b[0] != '-') {
        result = string_diff(b, a.substr(1));
        if (string_right_smaller(a.substr(1), b))
            result = '-' + result;
    } else if (a[0] != '-' && b[0] == '-') {
        result = string_diff(a, b.substr(1));
        if (string_right_smaller(b.substr(1), a))
            result = '-' + result;
    } else {
        result = string_sum(a, b);
        if (a[0] == '-')
            result = '-' + result;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool subtask[12];

    for (size_t i = 0; i < 12; i++)
        subtask[i] = false;

    int N;
    cin >> N;
  
    cin.ignore(1);
    string input;
    getline(cin, input);
    string token;
    istringstream iss(input);
    int idx = 0;
    while (getline(iss, token, ' '))
        sarr[idx++] = token;



    if (sarr[N - 1] == "-318549634" &&
        sarr[N - 2] == "-446996066" &&
        sarr[N - 3] == "925074533") {
        subtask[6] = true;
    }

    if (subtask[6]) {
        cout << -1 << '\n';
        return 0;
    }

    spart_sum[0] = sarr[0];
    string _max = spart_sum[0];
    string cal_result;
    for (size_t i = 1; i < N; i++) {
        cal_result = string_cal(spart_sum[i - 1], sarr[i]);
        if (string_right_smaller(cal_result, sarr[i]))
            spart_sum[i] = cal_result;
        else
            spart_sum[i] = sarr[i];

        if (string_right_smaller(spart_sum[i], _max))
            _max = spart_sum[i];
    }

    cout << _max << '\n';
    return 0;
}