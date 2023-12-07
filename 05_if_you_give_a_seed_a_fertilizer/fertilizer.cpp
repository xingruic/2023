// long long is required!!
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
vector<long long> seeds;
vector<bool> done;
int main() {
    freopen("fertilizer.in", "r", stdin);
    freopen("fertilizer.out", "w", stdout);
    string s;
    cin >> s;
    while (cin >> s && s[0] != 's') {
        seeds.push_back(atoll(s.c_str()));
    }
    done.resize(seeds.size());
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 's') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 'f') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 'w') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 'l') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 't') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 'h') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    fill(done.begin(), done.end(), 0);
    cin >> s;
    while (cin >> s && s[0] != 'h') {
        long long ds, ss, len; // destination start, source start, length
        ds = atoll(s.c_str());
        cin >> ss >> len;
        for (int i = 0; i < seeds.size();i++) {
            if (done[i]) continue;
            if (ss <= seeds[i] && seeds[i] < ss + len) {
                done[i] = 1;
                seeds[i] = ds + seeds[i] - ss;
            }
        }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << done[i] << ' ';
    }cout << endl;
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << ' ';
    }cout << endl;
    long long m = __LONG_LONG_MAX__;
    for (int i = 0; i < seeds.size(); i++) {
        m = min(m, seeds[i]);
    }
    cout << m << endl;
}