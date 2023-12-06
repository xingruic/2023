#include<iostream>
using namespace std;
int N;
char schem[200][200];
// schem[I][J] should be the first digit of a number
bool isAdjacent(int I, int J, int &j) {
    for (j = J; j < N && schem[I][j] >= '0' && schem[I][j] <= '9'; j++) {
        // cout << schem[I][j];
    }
    // cout << endl;
    if (J > 0 && schem[I][J - 1] != '.') return 1;
    if (j < N && schem[I][j] != '.') return 1;
    for (int i = J - 1; i <= j; i++) {
        if (i < 0 || i >= N) continue;
        if (I > 0) {
            if (schem[I - 1][i] != '.') return 1;
        }
        if (I < N - 1) {
            if (schem[I + 1][i] != '.') return 1;
        }
    }
    return 0;
}
int main() {
    freopen("gears.in", "r", stdin);
    freopen("gears.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < N; j++) {
            schem[i][j] = getchar();
        }
    }
    int sum = 0;
    int end;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ('0' <= schem[i][j] && schem[i][j] <= '9') {
                if (isAdjacent(i, j, end)) {
                    int num = 0;
                    for (int k = j; k < end; k++) {
                        num *= 10;
                        num += schem[i][k] - '0';
                    }
                    cout << num << ' ';
                    sum += num;
                }
                j = end;
            }
        }
        cout << endl;
    }
    cout << sum << endl;
}