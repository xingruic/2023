#include<iostream>
using namespace std;
string s, gid;
int i;
const int r = 12, g = 13, b = 14;
int main() {
    freopen("conundrum.in", "r", stdin);
    freopen("conundrum.out", "w", stdout);
    int sum = 0;
    while (cin >> s >> gid) {
        bool p = 0;
        do {
            cin >> i;
            cin >> s;
            cout << i << ' ' << s << ' ';
            switch (s[0]) {
            case 'r':
                if (i > r) p = 1;
                break;
            case 'g':
                if (i > g) p = 1;
                break;
            default:
                if (i > b) p = 1;
                break;
            }
            if (p) break;
        } while (s[s.size() - 1] == ',' || s[s.size() - 1] == ';');
        cout << endl;
        if (!p) sum += atoi(gid.substr(0, gid.size() - 1).c_str());
        else getline(cin, s);
    }
    cout << sum << endl;
}