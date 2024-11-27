#include <iostream>
using namespace std;

// 행 : M 사이트, 열 : N 사이트
long long dp[31][31];

void calculate()
{
    for (int i = 0; i <= 30; i++)
    {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int main()
{
    int T;
    cin >> T;

    calculate();

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        cout << dp[M][N] << '\n';
    }
}