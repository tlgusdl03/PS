#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> subSize;
vector<bool> visited;

int solve(int N, int R, vector<vector<int>> &input)
{
    int result = 1;
    visited[R] = true;

    for (int i : input[R])
    {
        if (!visited[i])
        {
            result += solve(N, i, input);
        }
    }

    subSize[R] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;
    subSize.resize(N + 1);
    visited.resize(N + 1);

    int U, V;
    vector<vector<int>> input(N + 1, vector<int>());
    for (int i = 0; i < N - 1; i++)
    {
        cin >> U >> V;
        input[U].push_back(V);
        input[V].push_back(U);
    }

    solve(N, R, input);

    for (int i = 0; i < Q; i++)
    {
        cin >> U;
        cout << subSize[U] << '\n';
    }
}