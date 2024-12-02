#include <iostream>
#include <vector>
using namespace std;
int K = 0;
vector<pair<int, int>> v;

void move(int N, int start, int to)
{
    v.push_back({start, to});
}

void hanoi(int N, int start, int to, int via)
{
    K++;
    if (N == 1)
    {
        move(1, start, to);
    }
    else
    {
        hanoi(N - 1, start, via, to);
        move(N, start, to);
        hanoi(N - 1, via, to, start);
    }
}
int main()
{
    int N;
    cin >> N;
    hanoi(N, 1, 3, 2);

    cout << K << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << '\n';
    }
}