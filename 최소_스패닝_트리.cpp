#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solve(int V, int E, auto &input)
{
    int result = 0;
    vector<bool> visited(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        int cost = current.first;
        int node = current.second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        result += cost;

        for (auto &e : input[node])
        {
            int next_cost = e.first;
            int next_node = e.second;
            if (!visited[next_node])
            {
                pq.push({next_cost, next_node});
            }
        }
    }

    return result;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> input(V + 1);
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        input[A].push_back({C, B});
        input[B].push_back({C, A});
    }

    cout << solve(V, E, input) << '\n';
}