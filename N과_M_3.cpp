#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void solve(int N, int M, int current)
{
    if (M == v.size())
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        // current가 이전 호출때 마지막으로 넣었던 원소를 뜻함
        if (current <= i)
        {
            v.push_back(i);
            solve(N, M, current);
            v.pop_back();
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    solve(N, M, 1);
}