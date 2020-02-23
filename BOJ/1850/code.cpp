#include <cstdio>
#include <cstring>
typedef long long ll;

char str[10000000];

int main() {
    ll a, b, c;
    scanf("%lld %lld", &a, &b);
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    memset(str, '1', a);
    puts(str);
    return 0;
}