#include<iostream>
using namespace std;
const int maxn = 5;
long long T[maxn], D[maxn];
int n = 0;
long long dist(long long m, long long t) {
    return (t - m) * m;
}
int main() {
    freopen("wait.in", "r", stdin);
    freopen("wait.out", "w", stdout);
    n = 1;
    T[0] = 48989083;
    D[0] = 390110311121360;
    long long ans = 1;
    for (int race = 0; race < n; race++) {
        int l = 0, r = T[race] / 2;
        int m;
        while (l != r) {
            m = (l + r) / 2;
            if (dist(m, T[race]) > D[race]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        ans *= (T[race] - l - l + 1);
    }
    cout << ans << endl;
}