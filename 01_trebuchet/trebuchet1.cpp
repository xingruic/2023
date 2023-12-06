#include<iostream>
#include<string>
using namespace std;
string s;
int d1, d2, sum = 0;
int main() {
    freopen("trebuchet.in", "r", stdin);
    while (!cin.eof()) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                d1 = s[i] - '0';
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                d2 = s[i] - '0';
                break;
            }
        }
        sum += d1 * 10 + d2;
    }
    cout << sum << endl;
}