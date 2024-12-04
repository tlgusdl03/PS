#include <iostream>
using namespace std;

int DP[40];

int main()
{
    int N;
    cin >> N;

    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2; i < 40; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    cout << DP[N - 1] << " " << N - 2;
}