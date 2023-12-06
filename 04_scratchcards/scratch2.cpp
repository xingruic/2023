#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxl = 100, maxr = 100;
struct card {
    vector<int> l, r;
};
vector<card> cards;
int cnt[1000];
int main() {
    for (int i = 0; i < 1000; i++) cnt[i] = 1;
    freopen("scratch.in", "r", stdin);
    freopen("scratch.out", "w", stdout);
    string s;
    cin >> s;
    int ncards = 0;
    while (cin >> s) {
        ncards++;
        card c = card();
        int id = atoi(s.substr(0, s.size() - 1).c_str());
        cin >> s;
        while (s != "|") {
            c.l.push_back(atoi(s.c_str()));
            cin >> s;
        }
        while (cin >> s && s != "Card") {
            c.r.push_back(atoi(s.c_str()));
        }
        sort(c.l.begin(), c.l.end());
        sort(c.r.begin(), c.r.end());
        int j = 0;
        int match = 0;
        for (int i = 0; i < c.r.size(); i++) {
            while (j < c.l.size() && c.l[j] < c.r[i]) {
                j++;
            }
            if (j == c.l.size()) break;
            if (c.l[j] == c.r[i]) match++;
        }
        cout << id << ' ' << match << endl;
        for (int i = 0; i < match; i++) {
            cnt[id + i] += cnt[id - 1];
        }
    }
    int sum = 0;
    for (int i = 0; i < ncards; i++) {
        sum += cnt[i];
    }
    cout << sum << endl;
}