#include <iostream>
using namespace std;

bool isSelected[8];
int numbers[8];

void solve(int N, int M, int current)
{
    if (current == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!isSelected[i])
        {
            isSelected[i] = true;
            numbers[current] = i + 1;
            solve(N, M, current + 1);
            isSelected[i] = false;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    solve(N, M, 0);
}