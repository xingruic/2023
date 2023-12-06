#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxl = 100, maxr = 100;
int L[maxl], R[maxr];
int main() {
    freopen("scratch.in", "r", stdin);
    freopen("scratch.out", "w", stdout);
    string s;
    cin >> s;
    int sum;
    while (cin >> s) {
        int id = atoi(s.substr(0, s.size() - 1).c_str());
        cin >> s;
        int lidx = 0, ridx = 0;
        while (s != "|") {
            L[lidx++] = atoi(s.c_str());
            cin >> s;
        }
        while (cin >> s && s != "Card") {
            R[ridx++] = atoi(s.c_str());
        }
        sort(L, L + lidx);
        sort(R, R + ridx);
        for (int i = 0; i < lidx; i++) cout << L[i] << ' ';
        cout << endl;
        for (int i = 0; i < ridx; i++) cout << R[i] << ' ';
        cout << endl;
        int cnt = 0;
        int l = 0;
        for (int i = 0; i < ridx; i++) {
            while (l < lidx && L[l] < R[i]) l++;
            if (l == lidx) break;
            if (L[l] == R[i]) {
                cnt++;
            }
        }
        int p = (cnt > 0);
        for (int i = 1; i < cnt; i++) p *= 2;
        sum += p;
        cout << id << ": " << cnt << ' ' << p << endl << endl;
    }
    cout << sum << endl;
}