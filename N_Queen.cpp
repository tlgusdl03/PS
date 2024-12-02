#include <iostream>
#include <vector>
using namespace std;

const int MAX = 15;

int N;
int result = 0;
vector<int> queens; // 각 행의 퀸이 놓인 열을 기록함

bool isItCanPlace(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void solve(int row)
{
    if (row == N)
    {
        result++;
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isItCanPlace(row, col))
        {
            queens[row] = col;
            solve(row + 1);
            queens[row] = -1;
        }
    }
}

int main()
{
    cin >> N;
    queens.resize(N, -1);
    solve(0);
    cout << result << '\n';
}