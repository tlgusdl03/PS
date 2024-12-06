#include <iostream>
#include <vector>
using namespace std;

int input[9][9];
vector<pair<int, int>> v;

bool check(int x, int y, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (input[i][y] == value)
            return false;
        if (input[x][i] == value)
            return false;
    }

    int subX = x / 3 * 3;
    int subY = y / 3 * 3;

    for (int i = subX; i < subX + 3; i++)
    {
        for (int j = subY; j < subY + 3; j++)
        {
            if (input[i][j] == value)
                return false;
        }
    }
    return true;
}

bool solve(int idx)
{
    if (idx == v.size())
    {
        return true;
    }

    int x = v[idx].first;
    int y = v[idx].second;

    for (int i = 1; i < 10; i++)
    {
        if (check(x, y, i))
        {
            input[x][y] = i;
            if (solve(idx + 1))
            {
                return true;
            }
            input[x][y] = 0;
        }
    }

    return false;
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input[i][j];
            if (input[i][j] == 0)
            {
                v.push_back({i, j});
            }
        }
    }

    for (pair<int, int> i : v)
    {
        int x = i.first;
        int y = i.second;

        solve(0);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << '\n';
    }
}