#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &input)
{
    vector<int> DP(n, 0);

    DP[0] = input[0];
    int result = input[0];

    for (int i = 1; i < n; i++)
    {
        DP[i] = max(DP[i - 1] + input[i], input[i]);
        if (result < DP[i])
        {
            result = DP[i];
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> input(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << solve(n, input) << '\n';
}