#include<iostream>
// #include<algorithm>
using namespace std;
int N;
char schem[200][200];
int numAt[200][200];
unsigned long long gearRatio[200][200];
int cnt[200][200];
// schem[I][J] should be a gear
void multGears(int I, int J, int &j) {
    for (j = J; j < N && schem[I][j] >= '0' && schem[I][j] <= '9'; j++) {
        // cout << schem[I][j];
    }
    // cout << endl;
    if (J > 0 && schem[I][J - 1] == '*') {
        cout << I << ' ' << J - 1 << endl;
        gearRatio[I][J - 1] *= numAt[I][J];
        cnt[I][J - 1]++;
    }
    if (j < N && schem[I][j] == '*') {
        cout << I << ' ' << j << endl;
        gearRatio[I][j] *= numAt[I][J];
        cnt[I][j]++;
    }
    for (int i = J - 1; i <= j; i++) {
        if (i < 0 || i >= N) continue;
        if (I > 0) {
            if (schem[I - 1][i] == '*') {
                cout << I - 1 << ' ' << i << endl;
                gearRatio[I - 1][i] *= numAt[I][J];
                cnt[I - 1][i]++;
            }
        }
        if (I < N - 1) {
            if (schem[I + 1][i] == '*') {
                cout << I + 1 << ' ' << i << endl;
                gearRatio[I + 1][i] *= numAt[I][J];
                cnt[I + 1][i]++;
            }
        }
    }
}
int main() {
    fill(&numAt[0][0], &numAt[0][0] + sizeof(numAt) / sizeof(numAt[0][0]), 0);
    fill(&gearRatio[0][0], &gearRatio[0][0] + sizeof(gearRatio) / sizeof(gearRatio[0][0]), 1);
    fill(&cnt[0][0], &cnt[0][0] + sizeof(cnt) / sizeof(cnt[0][0]), 0);
    freopen("gears.in", "r", stdin);
    freopen("gears.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < N; j++) {
            schem[i][j] = getchar();
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ('0' <= schem[i][j] && schem[i][j] <= '9') {
                for (int k = j; k < N && '0' <= schem[i][k] && schem[i][k] <= '9'; k++) {
                    numAt[i][j] *= 10;
                    numAt[i][j] += schem[i][k] - '0';
                }
            }
        }
    }
    int end;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ('0' <= schem[i][j] && schem[i][j] <= '9') {
                multGears(i, j, end);
                j = end;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cnt[i][j] > 1) {
                sum += gearRatio[i][j];
            }
        }
    }
    cout << sum << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << gearRatio[i][j] << '\t';
    //     }cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << cnt[i][j] << '\t';
    //     }cout << endl;
    // }
}