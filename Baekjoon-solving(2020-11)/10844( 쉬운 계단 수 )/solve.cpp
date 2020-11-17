#include <iostream>
using namespace std;
long long dp[101][11];
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    init();
    int N;
    cin >> N;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result += dp[N][i];
    }

    cout << result % 1000000000;
}
