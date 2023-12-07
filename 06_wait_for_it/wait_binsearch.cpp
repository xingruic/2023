#include<iostream>
using namespace std;
const int maxn = 5;
int T[maxn], D[maxn];
int n = 0;
int dist(int m, int t) {
    return (t - m) * m;
}
int main() {
    freopen("wait.in", "r", stdin);
    freopen("wait.out", "w", stdout);
    string s;
    cin >> s;
    while (cin >> s && s[0] != 'D') {
        T[n++] = atoi(s.c_str());
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        D[i] = atoi(s.c_str());
    }
    cout << n << endl;
    int ans = 1;
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