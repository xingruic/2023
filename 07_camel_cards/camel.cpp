#include<iostream>
using namespace std;
enum htype {
    FIVE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD
};
htype handType(string s) {
    sort(s.begin(), s.end());
    uint8_t cnt[5];
    for (int i = 0; i < 5; i++) {
        for (cnt[i] = 1; cnt[i] + i < 5 && s[cnt[i] + i] == s[cnt[i] + i - 1]; cnt[i]++);
        i += cnt[i] - 1;
    }
    // cout << s << ' ';
    // for (int i = 0; i < 5; i++) cout << (int)cnt[i];
    // cout << endl;
    sort(cnt, cnt + 5);
    switch (cnt[4]) {
    case 1:
        return HIGH_CARD;
    case 2:
        if (cnt[3] == 2) return TWO_PAIR;
        return ONE_PAIR;
    case 3:
        if (cnt[3] == 2) return FULL_HOUSE;
        return THREE_OF_A_KIND;
    case 4:
        return FOUR_OF_A_KIND;
    default:
        return FIVE_OF_A_KIND;
    }
}
struct hand {
    string s;
    htype h;
    int bid;
    hand(string s, int b) :s(s), bid(b) {
        h = handType(s);
    }
};
bool cmp(hand &a, hand &b) {
    if (a.h == b.h) {
        for (int i = 0; i < 5; i++) {
            if (a.s[i] == b.s[i]) continue;
            return a.s[i] < b.s[i];
        }
    }
    return a.h > b.h;
}
vector<hand> hands;
int main() {
    freopen("camel.in", "r", stdin);
    freopen("camel.out", "w", stdout);
    string s;
    int bid;
    while (cin >> s) {
        cin >> bid;
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'T') s[i] = '9' + 1;
            if (s[i] == 'J') s[i] = '9' + 2;
            if (s[i] == 'Q') s[i] = '9' + 3;
            if (s[i] == 'K') s[i] = '9' + 4;
        }
        hands.push_back(hand(s, bid));
    }
    sort(hands.begin(), hands.end(), cmp);
    long long sum = 0;
    for (int i = 0; i < hands.size(); i++) {
        sum += (i + 1) * hands[i].bid;
        cout << hands[i].h << ' ' << hands[i].s << ' ' << hands[i].bid << endl;
    }
    cout << sum << endl;
}