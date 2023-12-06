#include<iostream>
#include<algorithm>
using namespace std;
string s, gid;
int main() {
    freopen("conundrum.in", "r", stdin);
    freopen("conundrum.out", "w", stdout);
    int i;
    int mr, mg, mb;
    int sum = 0;
    while (cin >> s >> gid) {
        mr = 0, mg = 0, mb = 0;
        do {
            cin >> i;
            cin >> s;
            switch (s[0]) {
            case 'r':
                mr = max(mr, i);
                break;
            case 'g':
                mg = max(mg, i);
                break;
            default:
                mb = max(mb, i);
                break;
            }
        } while (s[s.size() - 1] == ',' || s[s.size() - 1] == ';');
        cout << mr << ' ' << mg << ' ' << mb << endl;
        sum += mr * mg * mb;
    }
    cout << sum << endl;
}