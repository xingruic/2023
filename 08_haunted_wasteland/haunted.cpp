#include<iostream>
#include<map>
using namespace std;
struct node {
    string id;
    node *l, *r;
    node(string id) :id(id) {}
};
string steps;
map<string, node *> m;
int main() {
    freopen("haunted.in", "r", stdin);
    freopen("haunted.out", "w", stdout);
    cin >> steps;
    string s, L, R;
    while (cin >> s >> L >> L >> R) {
        L = L.substr(1, 3), R = R.substr(0, 3);
        if (m.count(s) == 0) m[s] = new node(s);
        if (m.count(L) == 0) m[L] = new node(L);
        if (m.count(R) == 0) m[R] = new node(R);
        m[s]->l = m[L];
        m[s]->r = m[R];
    }
    node *cur = m["AAA"];
    int sid = 0, cnt = 0;
    while (cur->id != "ZZZ") {
        if (sid == steps.size()) sid = 0;
        if (steps[sid] == 'L') {
            cur = cur->l;
        } else {
            cur = cur->r;
        }
        sid++, cnt++;
    }
    cout << cnt << endl;
}