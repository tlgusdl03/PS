#include <iostream>
#include <vector>
using namespace std;

const int MOD = 15746;

int main()
{
    int N;
    cin >> N;

    vector<int> DP(N);
    DP[0] = 1;
    DP[1] = 2;

    if (N > 1)
    {
        for (int i = 2; i < N; i++)
        {
            DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
        }
    }

    cout << DP[N - 1] << '\n';
}