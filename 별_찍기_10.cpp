#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string> &s, int N, int top, int left)
{
    if (N == 3)
    {
        s[top + 1][left + 1] = ' ';
        return;
    }
    else
    {
        int subLength = N / 3;

        for (int i = top + subLength; i < top + subLength * 2; i++)
        {
            for (int j = left + subLength; j < left + 2 * subLength; j++)
            {
                s[i][j] = ' ';
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                solve(s, subLength, top + i * subLength, left + j * subLength);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<string> s(N, string(N, '*'));

    solve(s, N, 0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << s[i][j];
        }
        cout << '\n';
    }
}