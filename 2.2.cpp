#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

long long dp[200][200] = { 0 };
long long sum[200] = { 0 };

long long calculateSum(long long start, long long finish) {
    return sum[finish] - (start > 0 ? sum[start - 1] : 0);
}

int main() {
    int test;
    cin >> test;
    for (int t = 0; t < test; t++) {
        long long s = 0;
        long long length;
        cin >> length;

        for (long long c = 0; c < length; c++) {
            long long a;
            cin >> a;
            s += a;
            sum[c] = s;
        }

        for (long long l = 1; l < length; l++) {
            for (long long i = 0; i < length - l; i++) {
                long long j = i + l;
                dp[i][j] = 10001;

                for (long long k = i; k < j; k++) {
                    long long tmp = dp[i][k] + dp[k + 1][j] + calculateSum(i, j);
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }
        cout << dp[0][length - 1] << "\n";
    }
}


