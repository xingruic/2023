#include<iostream>
#include<string>
#include<regex>
#include<algorithm>
#include<map>
using namespace std;
string s;
int d1, d2, sum = 0;
map<string, int> number = {
    {"1",1},{"one",1},
    {"2",2},{"two",2},
    {"3",3},{"three",3},
    {"4",4},{"four",4},
    {"5",5},{"five",5},
    {"6",6},{"six",6},
    {"7",7},{"seven",7},
    {"8",8},{"eight",8},
    {"9",9},{"nine",9}
};
int match(int x) {
    for (int i = x; i < s.size(); i++) {
        for (auto j : number) {
            if (i + j.first.size() > s.size()) continue;
            // cout << s.substr(i, j.first.size()) << ' ' << j.first << endl;
            if (s.substr(i, j.first.size()) == j.first) {
                return j.second;
            }
        }
    }
    return -1;
}
int main() {
    freopen("trebuchet.in", "r", stdin);
    freopen("trebuchet.out", "w", stdout);
    while (!cin.eof()) {
        cin >> s;
        d1 = match(0);
        for (int i = s.size() - 1; i >= 0; i--) {
            if ((d2 = match(i)) > -1) {
                break;
            }
        }
        sum += d1 * 10 + d2;
        cout << d1 << d2 << endl;
    }
    cout << endl << sum << endl;
}